class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0; 
        vector<vector<int>> dp(k+1, vector<int>(2, -1e9));
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        int ans = 0;
        
        // dp[k][0] = maximum profit on previous days (0 to i-1), completed k transactions, currently sold
        // dp[k][1] = maximum profit on previous days (0 to i-1), completed k transactions, currently buying
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                
                // We can buy at day i, or not.
                int new_bought = max(dp[j][0] - prices[i], dp[j][1]);
                
                // We can sell at day i (if already bought something), or not.
                int new_sold = dp[j][0];
                if (j > 0)
                    new_sold = max(new_sold, dp[j-1][1] + prices[i]);
                
                dp[j][0] = new_sold;
                dp[j][1] = new_bought;
                
                if (i == n - 1)
                    ans = max(ans, dp[j][0]);
            }
        }
        
        return ans;
    }
};
