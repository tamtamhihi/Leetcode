class Solution {
public:
    int numDecodings(string s) {
        // If there's leading zeros, there's no way 
        // we could decode the string.
        if (s[0] == '0')
            return 0;
        
        // dp[i] = number of ways to decode first i numbers
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= s.size(); ++i) {
            // If the i-th number is not '0',
            // we can decode this to be a single
            // character. The number of ways if dp[i-1].
            if (s[i-1] != '0')
                dp[i] = dp[i-1];
            
            // The i-th number might be appended to
            // the previous number to become a value
            // from 10 to 26.
            if (i >= 2) {
                if (s[i-2] == '1')
                    dp[i] += dp[i-2];
                else if (s[i-2] == '2' && s[i-1] <= '6')
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
