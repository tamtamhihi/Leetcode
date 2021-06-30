class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // We sort the array so that similar values are next to each other,
        // and we can avoid listing duplicate quadruplets.
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        // In order to list distinct triplets, we try to make the result
        // in non-decreasing order.
        
        // nums[i] will be the first (a.k.a smallest) value.
        for (int i = 0; i < n - 2; ++i) {
            
            // Avoid duplicate values for first position.
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            // Here we use two pointers technique to find the remaining 2 values
            // where their sum = target - nums[i]
            int l = i + 1, r = n - 1;
            
            while (l < r) {
                // Avoid duplicates
                while (l > i + 1 && l < r && nums[l] == nums[l-1]) {
                    ++l; 
                }
                while (r < n - 1 && r > l && nums[r] == nums[r+1]) {
                    --r;
                }
                if (l == r)
                    break;
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> a(3);
                    a[0] = nums[i], a[1] = nums[l], a[2] = nums[r];
                    ans.push_back(a);
                    ++l;
                    --r;
                } else if (sum < 0) {
                    // The current sum is small, we need to increase nums[l].
                    ++l;
                } else {
                    // The current sum is large, we need to decrease nums[r].
                    --r;
                }
            }
            
        }
        return ans;
    }
};