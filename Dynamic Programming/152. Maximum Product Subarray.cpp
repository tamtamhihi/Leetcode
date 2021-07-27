class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minDp = nums[0], maxDp = nums[0], newMinDp;
        int ans = nums[0];
        
        // We always keep the min and max value,
        // in case the smallest, negative value
        // from previous subarray meets a negative value.
        for (int i = 1; i < n; ++i) {
            newMinDp = min(nums[i], min(minDp * nums[i], maxDp * nums[i]));
            maxDp = max(nums[i], max(minDp * nums[i], maxDp * nums[i]));
            minDp = newMinDp;
            ans = max(ans, maxDp);
        }
        return ans;
    }
};
