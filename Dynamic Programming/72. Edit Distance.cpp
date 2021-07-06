class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // dp[i][j] = min distance to match first i and j chars of word1, word2
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
        
        // Having to match nothing, so min distance = 0.
        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                
                if (word1[i-1] != word2[j-1]) {
                    // Insert word2[j] into i+1 position of word1 --> 1 + dp[i][j-1]
                    // Delete i-th char of word1 --> 1 + dp[i-1][j]
                    // Replace word1[i] = word2[j] --> 1 + dp[i-1][j-1]
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
                    
                else {
                    // No change is required.
                    dp[i][j] = dp[i-1][j-1];
                }
                    
            }
        }
        
        return dp[n][m];
    }
};
