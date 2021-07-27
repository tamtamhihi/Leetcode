class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Mark if a day is in the set.
        vector<bool> isIn(366, false);
        for (int day : days)
            isIn[day] = true;
        
        // dp[i] = cost to afford from day i to day 365.
        vector<int> dp(366);
        for (int day = 365; day >= 1; --day) {
            // If this day is not in the set, we don't need to buy the ticket.
            if (isIn[day] == false) {
                dp[day] = day + 1 <= 365 ? dp[day + 1] : 0;
            }
            else {
                // Try buying 3 kinds of tickets and keep the minimum cost.
                dp[day] = costs[0] + (day + 1 <= 365 ? dp[day + 1] : 0);
                dp[day] = min(dp[day], costs[1] + (day + 7 <= 365 ? dp[day + 7] : 0));
                dp[day] = min(dp[day], costs[2] + (day + 30 <= 365 ? dp[day + 30] : 0));
            }
        }
        return dp[1];
    }
};
