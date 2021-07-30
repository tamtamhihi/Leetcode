#define ll long long

class Solution {
public:
    ll M = 1e9 + 7;
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        // dp[i] = number of ways to decode first i characters.
        vector<ll> dp(s.size() + 1, 0);
        dp[0] = 1;
        if (s[0] == '*')
            dp[1] = 9;
        else
            dp[1] = 1;
        
        for (int i = 2; i <= s.size(); ++i) {
            // One digit
            if (s[i-1] == '*') // replace with [1, 9] - 9 options
                dp[i] = (dp[i-1] * 9) % M;
            else if (s[i-1] != '0') // 1 option
                dp[i] = dp[i-1];
            
            // Two digits --> examine the previous character
            if (s[i-2] == '1') {
                if (s[i-1] == '*') { // replace with [1, 9] - 9 options
                    dp[i] += (dp[i-2] * 9) % M;
                    dp[i] %= M;
                }
                else { // 1 option
                    dp[i] += dp[i-2];
                    dp[i] %= M;
                }
            } else if (s[i-2] == '2') {
                if (s[i-1] == '*') { // replace with [1, 6] - 6 options
                    dp[i] += (dp[i-2] * 6) % M;
                    dp[i] %= M;
                } else if (s[i-1] <= '6') { // 1 option
                    dp[i] += dp[i-2];
                    dp[i] %= M;
                }
            } else if (s[i-2] == '*') {
                if (s[i-1] == '*') { // Replace 2 asterisks with [11, 19] + [21, 26]
                    dp[i] += dp[i-2] * 15;
                    dp[i] %= M;
                } else if (s[i-1] > '6') { // Replace the previous asterisk with '1'
                    dp[i] += dp[i-2];
                    dp[i] %= M;
                } else { // Replace asterisk with '1' or '2' is both ok.
                    dp[i] += dp[i-2] * 2;
                    dp[i] %= M;
                }
            } else if (s[i-1] == '0') { // invalid '0' in middle of string.
                return 0;
            }
        }
        return dp[s.size()];
    }
};
