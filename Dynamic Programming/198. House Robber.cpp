class Solution {
public:
    int rob(vector<int>& nums) {
        int robbed = nums[0], not_robbed = 0;
        int new_robbed;
        for (int i = 1; i < nums.size(); ++i) {
            // If we rob at day i, we must not rob
            // at the previous day.
            new_robbed = not_robbed + nums[i];
            
            // It we don't rob at day i, we can both
            // rob or not rob at previous day.
            not_robbed = max(not_robbed, robbed);
            
            robbed = new_robbed;
        }
        return max(robbed, not_robbed);
    }
};
