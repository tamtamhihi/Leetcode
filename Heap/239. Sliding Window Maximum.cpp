class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> window, removed;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k)
                removed.push(nums[i-k]);
            window.push(nums[i]);
            while (!window.empty() && !removed.empty() && window.top() == removed.top()) {
                window.pop();
                removed.pop();
            }
            if (i >= k-1)
                ans.push_back(window.top());
        }
        return ans;
    }
};
