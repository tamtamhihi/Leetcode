class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();     
        
        // dp[i][0] = maximum profit of i+1 days, currently sold
        // dp[i][1] = maximum profit of i+1 days, currently buying
        
        // vector<vector<int>> dp(n, vector<int>(2, -1e9));        
        // dp[0][0] = 0; 
        // dp[0][1] = -prices[0];         
        
        // Optimize by using only 2 variables to represent dp[i-1][0] and dp[i-1][1]
        int sold = 0, bought = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            
            // We could sell at day i, or not.
            
            // dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            int new_sold = max(sold, bought + prices[i]);
            
            // We could buy at day i, or not.
            
            // dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
            bought = max(bought, sold - prices[i]);
            
            sold = new_sold;
        }
        
        return max(0, sold);
    }
};
