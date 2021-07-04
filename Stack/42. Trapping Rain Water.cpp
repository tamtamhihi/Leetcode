class Solution {
public:
    
    // The key idea: Jump to each column C (from left to right),
    // find the first column D to its right such D's height >= C's height.
    // This would be a container for water and cannot be extended. (of course
    // after this, the columns in between this container will be jumped over).
    
    // If cannot find D, find a smaller column E to C's right such that:
    //      i) the columns in between C and E must be smaller than E's height
    //         --> C is E's first larger-or-equal column to the left
    //      ii) E is farthest to the right
    //         --> E is the first column from right that satisfies above condition
    
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightFirstNotSmaller(n, -1);
        vector<int> farthestBorderCol(n);
        stack<int> s;
        
        // Loop from right to left, and pop out heights from stack
        // which is <= current height. The last one to be popped out
        // is the farthest border.
        for (int i = n-1; i >= 0; --i) {
            int current = height[i];
            int last = -1;
            while (s.empty() == false && current >= height[s.top()]) {
                last = s.top();
                s.pop();
            }
            farthestBorderCol[i] = last;
            s.push(i);
        }
        
        while (s.empty() == false)
            s.pop();
        
        // Loop from left to right, pop out heights from stack
        // which is <= current height. Current column would be
        // the first column to the right that is >= the popped columns.
        for (int i = 0; i < n; ++i) {
            int current = height[i];
            while (s.empty() == false && current >= height[s.top()]) {
                rightFirstNotSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
    
        // Implement prefix sum to calculate the amount of trapped rain.
        vector<int> prefixSum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + height[i];
        }
        
        int rain = 0;
        
        for (int i = 0; i < n; ++i) {
            int border;
            if (rightFirstNotSmaller[i] == -1) {
                border = farthestBorderCol[i];
            } else {
                border = rightFirstNotSmaller[i];
            }
            if (border - i <= 1)
                continue;
            int h = min(height[i], height[border]);
            
            // The total rain in container [i, border]
            // is sum(h - height[k]) for k in [i+1, border-1]
            // = h * num - sum(height[k]) for k in [i+1, border-1]
            
            int num = border - i - 1;
            rain += h * num - (prefixSum[border] - prefixSum[i+1]);

            i = border-1; // border can still be the left border of another container.
        }
        return rain;
    }
};
