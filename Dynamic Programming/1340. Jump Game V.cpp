class Solution {
public:
    // dp[i] = maximum indices we can visit if we start from i
    vector<int> dp;

    int jump(int index, vector<int>& arr, int d) {
        if (dp[index] != -1)
            return dp[index];
        dp[index] = 0;
        
        // Try all possible positions within d steps
        // and save the maximum results.
        
        for (int i = index - 1; i >= index - d && i >= 0; --i) {
            if (arr[i] >= arr[index])
                break;
            dp[index] = max(dp[index], jump(i, arr, d));
        }
        
        for (int i = index + 1; i <= index + d && i < arr.size(); ++i) {
            if (arr[i] >= arr[index])
                break;
            dp[index] = max(dp[index], jump(i, arr, d));
        }
        
        // Plus the result with 1 (indicating the current index)
        dp[index] += 1;
        
        return dp[index];
    }
    
    int maxJumps(vector<int>& arr, int d) {
        dp.resize(arr.size(), -1);
        int ans = 0;
        
        // Try to start jumping at all indices
        // and save the maximum results.
        for (int i = 0; i < arr.size(); ++i) {
            if (dp[i] == -1) {
                jump(i, arr, d);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
