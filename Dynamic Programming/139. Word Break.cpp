class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] = true if we can break down from character 
        // at position i to n-1
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        
        // Turn wordDict into set.
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        for (int i = s.size() - 1; i >= 0; --i) {
            string temp = "";
            // Try all possibilities and stop when
            // finding a true.
            for (int j = i; j < s.size(); ++j) {
                temp += s[j];
                if (dict.find(temp) != dict.end() && dp[j+1] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
