class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer(n, 0);
        
        stack<int> s;
        
        // The number of shorter heights that heights[i] can see
        // == the number of heights[j] to the right of i such that
        // heights[i] is the FIRST left taller of heights[j].
        
        for (int i = n-1; i >= 0; --i) {
            // heights[i] is first taller than s.top()
            while (s.empty() == false && heights[s.top()] < heights[i]) {
                answer[i] += 1;
                s.pop();
            }
            s.push(i);
        }
        
        // Clean stack
        while (s.empty() == false)
            s.pop();

        // However, each heights[i] can see 1 more person that is 
        // FIRST right taller.
        for (int i = 0; i < n; ++i) {
            // heights[i] is first right taller than s.top()
            while (s.empty() == false && heights[s.top()] < heights[i]) {
                answer[s.top()] += 1;
                s.pop();
            }
            s.push(i);
        }
        
        return answer;
    }
};
