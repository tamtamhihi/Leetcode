class Solution {
public:
    #define ull unsigned long long
    int numDistinct(string s, string t) {
        
        // We define dp[i][j] = number of subsequences in 
        // first i characters of s that matches first j characters of t.
        
        int m, n;
        m = s.size(), n = t.size();
        
        // Although dp[m][n] is guaranteed to fit in 32 bits,
        // dp[m][j] with j < n is not (having to match fewer characters).
        // We use unsigned long long here.
        
        vector<vector<ull>> dp(m+1, vector<ull>(n+1, 0));
        
        // j = 0 means that we have to match nothing,
        // so there is 1 string ("")
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                
                // If this character matches, the number of matched subsequences
                // = previous matched subsequences (dp[i-1][j])
                //   + new ones by using s[i-1] (dp[i-1][j-1])
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                
                // Else, only the previous matched subsequences is counted.
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
        
        
        // Note that at any time, we only need dp[i] and dp[i-1] to calculate.
        // We can optimize this solution by storing 1 row at a time.
        
        // vector<ull> dp(n+1, 0); // represents dp[i-1], firstly dp[0]
        // dp[0] = 1; // dp[0][0]
        
        // for (int i = 1; i <= m; ++i) {
         
        //    int previous = 1; // it represents dp[i-1][j-1]
            
        //    for (int j = 1; j <= n; ++j) {
                
        //        int temp = dp[j];
                
        //        if (s[i - 1] == t[j - 1]) {
        //            dp[j] = previous + dp[j];
        //        } else {
        //            dp[j] = dp[j];
        //        }
        
        //        previous = temp;
        //    }
            
        //}
        //return dp[n];
    }
};
