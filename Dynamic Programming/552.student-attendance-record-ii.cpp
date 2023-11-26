/*
https://leetcode.com/problems/student-attendance-record-ii/

DP thought process:

1. Simplest formula: dp[i] = number of records of length i

2. Since we allow < 2 absent days: dp[i][j] (j = 0, 1) = number of records of length i with j absent days

3. Since we allow max 2 consecutive late days: dp[i][j][k] (k = 0, 1, 2) = number of records of length i with j absent days ending with strictly one 'L' if k = 1 or with strictly 2 'L' if k = 2

The result is sum(dp[n][j][k]) for all j in [0, 1] and k in [0, 2].
*/

class Solution {
public:
    int checkRecord(int n) {
        int M = 1e9 + 7;
      
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        dp[0][0][0] = 1; // there is one empty record that satisfies: 0 absent day, 0 ending 'L'

        for (int i = 1; i <= n; ++i) {
            // no 'A', no ending 'L' => Position i has only one choice ('P')
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2];
          
            // 1 'A', no ending 'L' => The letter 'A' is either at position i or in previous (i-1) characters
            dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) + (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]);

            // no 'A', 1 ending 'L'
            dp[i][0][1] = dp[i-1][0][0];

            // 1 'A', 1 ending 'L'
            dp[i][1][1] = dp[i-1][1][0];

            // no 'A', 2 ending 'L' => Grab the previous strictly 1 ending 'L'
            dp[i][0][2] = dp[i-1][0][1];

            // 1 'A', 2 ending 'L'
            dp[i][1][2] = dp[i-1][1][1];

            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    dp[i][j][k] %= M;
                }
            }
        }

        int result = 0;
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                result = (result + dp[n][j][k]) % M;
            }
        }
        return result;
    }
};
