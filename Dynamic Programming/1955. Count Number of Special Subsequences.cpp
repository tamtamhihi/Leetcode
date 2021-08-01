class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int M = 1e9 + 7;

        int zero = 0, one = 0, two = 0;
        if (nums[0] == 0) {
            zero = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                // old 0-end subsequences 
                // + append current 0 to old 0-end subsequences
                // + start a new subsequence with this 0.
                zero = (zero + (zero + 1) % M) % M;
            }
            else if (nums[i] == 1) {
                // old 1-end subsequences 
                // + append current 1 to old 1-end subsequences
                // + append current 1 to old 0-end subsequences
                one = (one + (one + zero) % M) % M;
            } 
            else {
                // old 2-end subsequences 
                // + append current 2 to old 2-end subsequences
                // + append current 2 to old 1-end subsequences
                two = (two + (two + one) % M) % M;
            }
        }
        
        return two % M;
    }
};
