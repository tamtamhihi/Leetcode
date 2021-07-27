class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // Sort the envelopes in increasing order.
        sort(envelopes.begin(), envelopes.end());
        
        // dp[i] = number of envelopes in russian doll
        // ending with envelopes[i].
        vector<int> dp(n, 1);
        dp[0] = 1;
        
        int ans = 1;
        
        // For each envelopes[i]
        for (int i = 1; i < n; ++i) {
            // Loop through previous envelopes[j]
            for (int j = i - 1; j >= 0; --j) {
                // If we can put envelopes[j] inside envelopes[i],
                // we achieve dp[j] + 1 envelopes.
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
