class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        // liketimeCoeff of i last elements
        // = 1 * s[n-i] + 2 * s[n-i+1] + ... + i * s[n-1]
        // = (s[n-i] + ... + s[n-1]) + (1 * s[n-i+1] + .. + (i-1) * s[n-1])
        // = sum(last i elements) + (liketimeCoeff of last i-1 elements)
        
        sort(satisfaction.begin(), satisfaction.end());
        int answer = 0;
        int sum = 0;
        int liketimeCoeff = 0;
        for (int i = satisfaction.size() - 1; i >= 0; --i) {
            sum += satisfaction[i];
            liketimeCoeff = sum + liketimeCoeff;
            answer = max(answer, liketimeCoeff);
        }
        return answer;
    }
};
