class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            // Find the middle index.
            int m = (l + r) / 2;
            
            // If middle value is smaller than right value,
            // [m, r] is increasing. Hence, the only value
            // in this segment that could be the minimum value
            // is nums[m] if and only if it's smaller than
            // nums[m-1]. Otherwise, we decrease r to m-1.
            if (nums[m] < nums[r]) {
                if (m == l || nums[m-1] > nums[m])
                    return nums[m];
                r = m - 1;
            }
            
            // If middle value is larger than right value,
            // [l, m] is increasing so it cannot contains
            // the minimum value.
            else if (nums[m] > nums[r]) {
                l = m + 1;
            }
            
            // If middle value equals right value, it means
            // that l = r = m, so we return this value.
            else {
                return nums[m];
            }
        }
        
        return nums[l];
    }
};
