class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2)
            return false;
        
        // dp[i][j] = true if we can interleave first i, j characters
        // of s1, s2 to first k=i+j characters of s3
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        
        dp[0][0] = true;
        for (int i = 0; i < n1; ++i) {
            if (s1[i] != s3[i])
                break;
            dp[i+1][0] = true;
        }
        for (int j = 0; j < n2; ++j) {
            if (s2[j] != s3[j])
                break;
            dp[0][j+1] = true;
        }
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                int k = i + j;
                if (s1[i-1] == s3[k-1] && dp[i-1][j]) {
                    dp[i][j] = true;
                }
                if (s2[j-1] == s3[k-1] && dp[i][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
    }
};
