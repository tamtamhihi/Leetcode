class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // dp[i] = all ways of breaking down
        // from character at position i to n-1
        vector<vector<string>> dp(s.size() + 1);
        dp[s.size()].push_back("");
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // Find all possibilities
        for (int i = s.size() - 1; i >= 0; --i) {
            string temp = "";
            for (int j = i; j < s.size(); ++j) {
                temp += s[j];
                if (dict.find(temp) != dict.end()) {
                    for (string str : dp[j+1]) {
                        if (str == "")
                            dp[i].push_back(temp);
                        else
                            dp[i].push_back(temp + " " + str);
                    }
                }
            }
        }
        
        return dp[0];
    }
};
