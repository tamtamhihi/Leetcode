class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Dif = Closest Sum - Target
        int dif = 1e9;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // We consider nums[i] to be the smallest in the triplet.
        for (int i = 0; i < n - 2; ++i) {
            
            // Use two pointers technique to find remaining 2 values
            int l = i + 1, r = n - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                // For each sum, we update dif with curDif.
                int curDif = sum - target;
                
                if (sum < target) {
                    dif = abs(curDif) < abs(dif) ? curDif : dif;
                    // We can reduce curDif by increasing the sum.
                    l++;
                } else if (target < sum) {
                    dif = abs(curDif) < abs(dif) ? curDif : dif;
                    // We can reduce curDif by decreasing the sum.
                    r--;
                } else {
                    // The difference is 0, so this must be
                    // the most closest sum ever!!
                    return target;
                }
            }
        }
        return target + dif;
    }
};