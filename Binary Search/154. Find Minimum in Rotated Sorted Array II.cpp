class Solution {
public:
    // It works the same as Leetcode
    // 153. Find Minimum in Rotated Sorted Array.
    
    // However, we have to take care for duplicate values.
    int findMinInSegment(vector<int>& nums, int l, int r) {
        if (l > r)
            return 1e9;
        
        while (l <= r) {
            // Find middle index.
            int m = (l + r) / 2;
            
            // If middle value is smaller than right value,
            // [m, r] is increasing so the only value that
            // could be minimum is nums[m], if and only if
            // nums[m] < nums[m-1]
            if (nums[m] < nums[r]) {
                if (m == l || nums[m-1] > nums[m])
                    return nums[m];
                r = m - 1;
            } 
            
            // If middle value is larger than right value,
            // [l, m] is increasing and cannot contains 
            // minimum value.
            else if (nums[m] > nums[r]) {
                l = m + 1;
            } 
            
            // Middle value equals right value.
            else {
                // Now we take care the left value.
                
                // If middle value is larger than left value,
                // we have nums[l] < nums[m] = nums[r]. So
                // minimum value is nums[l]
                if (nums[m] > nums[l])
                    return nums[l];
                
                // If middle value is smaller than left value,
                // we have nums[m] = nums[r] < nums[l], so [m, r]
                // is the "increasing" part. So the only value
                // in [m, r] that can be the minimum is nums[m].
                else if (nums[m] < nums[l]) {
                    if (m == l || nums[m-1] > nums[m])
                        return nums[m];
                    r = m - 1;
                }
                
                // nums[l] = nums[m] = nums[r].
                // We cannot be sure where the minimum value
                // is ([l, m-1] or [m+1, r]), so we need to
                // make a recursive call.
                else {
                    if (m == l || nums[m-1] > nums[m])
                        return nums[m];
                    if (nums[m-1] < nums[m])
                        r = m - 1;
                    else {
                        int left = findM(nums, l, m-1);
                        int right = findM(nums, m + 1, r);
                        return min(left, right);
                    }
                }
            }
        }
        return nums[l];
    }
    int findMin(vector<int>& nums) {
        return findM(nums, 0, nums.size() - 1);
    }
};
