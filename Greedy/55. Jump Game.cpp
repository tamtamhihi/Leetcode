class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // <reach> keeps track of the maximal reached index.
        // Stop as soon as i exceeds <reach>.
        int i = 0, reach = 0;
        
        for (int i = 0; i < n && i <= reach; ++i) {
            reach = max(reach, i + nums[i]);
        }
        
        return reach >= n-1;
        
        /*
        
        // O(n^2) DP solution
        
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;
        
        // For each beginning index, find if we can go to end
        // by trying each step.
        
        for (int left = n-2; left >= 0; --left) {
            for (int step = min(nums[left], n-left); step >=1 ; --step) {
                if (dp[left+step]) {
                    dp[left] = true;
                    break;
                }
            }
        }
        return dp[0];
        
        */
    }
};
