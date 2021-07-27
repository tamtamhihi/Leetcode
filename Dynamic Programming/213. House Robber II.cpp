class Solution {
public:
    int rob(vector<int>& nums) {
        // Rob from house 0 to house n-2
        int robbed = nums[0], not_robbed = 0;
        int new_robbed;
        for (int i = 1; i < nums.size() - 1; ++i) {
            new_robbed = not_robbed + nums[i];
            not_robbed = max(robbed, not_robbed);
            robbed = new_robbed;
        }
        int ans = max(robbed, not_robbed);
        
        // Rob from house n-1 to house 1
        robbed = nums.back(), not_robbed = 0;
        for (int i = nums.size() - 2; i > 0; --i) {
            new_robbed = not_robbed + nums[i];
            not_robbed = max(robbed, not_robbed);
            robbed = new_robbed;
        }
        
        return max(ans, max(robbed, not_robbed));
    }
};
