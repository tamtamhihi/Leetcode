class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0, reach = 0;
        
        // We use BFS idea: traverse the range of indices
        // that can be reached in 1 step, then 2 steps, etc.
        
        // <start>, <end> acts like 2 pointers marking the queue.
        
        int step = 0;
        
        while (end < n - 1) {
            ++step;
            
            // For each index in current step's range,
            // find the next maximum range
            for (; start <= end; ++start) {
                reach = max(nums[start] + start, reach);
                if (reach >= n - 1)
                    return step;
            }
            
            // Cannot extend more
            if (reach == end)
                break;
            
            end = reach;
        }
        
        return step;
        
        /*
        
        // O(n^2) DP solution
        
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[n-1] = 0;
        
        // For each beginning index, find if we can go to end
        // by trying each step.
        
        for (int left = n-2; left >= 0; --left) {
            for (int step = min(nums[left], n-left-1); step >=1 ; --step) {
                dp[left] = min(dp[left], 1 + dp[left + step]);
            }
        }
        return dp[0];
        
        */
    }
};
