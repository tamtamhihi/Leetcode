class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        // Reverse the whole array.
        int l = 0, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l += 1;
            r -= 1;
        }
        
        // Then reverse the first k elements, and reverse the last n-k elements.
        l = 0, r = k-1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l += 1;
            r -= 1;
        }
        l = k, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l += 1;
            r -= 1;
        }
    }
};
