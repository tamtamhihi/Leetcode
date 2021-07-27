class Solution {
public:
    // Lower bound: find the first element in arr (representing
    // indices in nums) that nums[element] >= v.
    int bisect(vector<int>& nums, vector<int>& arr, int v) {
        int l = 0, r = arr.size() - 1;
        int ans = r;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[arr[m]] >= v) {
                ans = m;
                r = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // Save the increasing array
        vector<int> arr;
        arr.push_back(0);
        
        vector<int> dp(n);
        dp[0] = 1;
        
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            // Increase LIS
            if (nums[i] > nums[arr.back()]) {
                dp[i] = arr.size() + 1;
                arr.push_back(i);
            }
            
            // Find the longest possible increasing subsequence
            else {
                int pos = bisect(nums, arr, nums[i]);
                dp[i] = dp[arr[pos]];
                arr[pos] = i;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
