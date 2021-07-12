class Solution {
public:
    
    // Returns true if a should appears before b to make a larger number.
    static bool compare(string& a, string& b) {
        string s = a + b, t = b + a;
        return s > t;
    }
    string largestNumber(vector<int>& nums) {
        // Convert all nums to string.
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strs[i] = to_string(nums[i]);
        }
        
        sort(strs.begin(), strs.end(), compare);
        
        string answer = "";
        for (string& s : strs) {
            answer += s;
        }
        return answer[0] == '0' ? "0" : answer;
    }
};
