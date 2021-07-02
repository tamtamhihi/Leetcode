class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int profit = 0;
        
        // If we sell at day i, we will want to buy 
        // at the previous day with the minimum price.
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]); // Update min price.
        }
        
        return profit;
    }
};
