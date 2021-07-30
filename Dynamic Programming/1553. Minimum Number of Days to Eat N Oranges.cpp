class Solution {
public:
    // dp[i] = min days to eat i oranges
    unordered_map<int, int> dp;
    
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (dp.find(n) != dp.end())
            return dp[n];
        // If we want to eat half, we have to eat 1 orange
        // per day in (n%2) days. Then we need 1 more day
        // to eat floor(n/2) oranges and the rest is called recursively.
        int second_choice = (n % 2) + 1 + minDays(n / 2);
        
        // Similarly, we eat 1 orange per day in (n%3) days.
        // 1 day to eat (2n/3) oranges and the rest is called recursively.
        int third_choice = (n % 3) + 1 + minDays(n / 3);
        
        dp[n] = min(second_choice, third_choice);
        return dp[n];
    }
};
