class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // We sort the array so that similar values are next to each other,
        // and we can avoid listing duplicate quadruplets.
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        // In order to list distinct quadruplets, we try to make the result
        // in non-decreasing order.
        
        // nums[i] will be the first (a.k.a smallest) value.
        for (int i = 0; i < n - 3; ++i) {
            
            // Avoid duplicate values for first position.
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            // nums[j] will be the second (a.k.a second smallest)
            for (int j = i + 1; j < n - 2; ++j) {
                
                // Again, no duplicate.
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                
                // Here we use two pointers technique to find the remaining 2 values
                // where their sum = target - (nums[i] + nums[j])
                int l = j + 1, r = n - 1;
                
                while (l < r) {
                    
                    // Avoid duplicates
                    while (l > j + 1 && l < r && nums[l] == nums[l-1]) {
                        ++l; 
                    }
                    while (r < n - 1 && r > l && nums[r] == nums[r+1]) {
                        --r;
                    }
                    if (l == r)
                        break;
                    long long sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        vector<int> a(4);
                        a[0] = nums[i], a[1] = nums[j];
                        a[2] = nums[l], a[3] = nums[r];
                        ans.push_back(a);
                        ++l;
                        --r;
                    } else if (sum < target) {
                        // The current sum is small, we need to increase nums[l].
                        ++l;
                    } else {
                        // The current sum is large, we need to decrease nums[r].
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};