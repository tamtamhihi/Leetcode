class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[3][2];
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = dp[1][1] = dp[2][0] = dp[2][1] = -1e9;
        
        // dp[k][0] = maximum profit of previous days (0 to i-1), currently sold
        // dp[k][1] = maximum profit of previous days (0 to i-1), currently buying
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 0; k <= 2; ++k) {
                
                // We can buy at day i, or not.
                int new_bought = max(dp[k][0] - prices[i], dp[k][1]);
                
                // We can sell at day i (if already bought something), or not.
                int new_sold = dp[k][0];
                if (k > 0)
                    new_sold = max(new_sold, dp[k-1][1] + prices[i]);
                
                dp[k][0] = new_sold;
                dp[k][1] = new_bought;
            }
        }
        return max(0, max(dp[1][0], dp[2][0]));
    }
};
