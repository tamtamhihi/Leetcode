class Solution {
public:
    // Change words into a set.
    unordered_set<string> wordsSet;
    
    // A copy of <words>
    vector<string> words;
    
    // Memoization table: dp[str][i] = true 
    // if substring words[str][i:] is a concatenation
    vector<vector<int>> dp;
    
    // Check if words[str][i:] is a concatenation
    bool isConcat(int str, int i) {
        int n = words[str].size();
        if (i >= n)
            return true;
        if (dp[str][i] != -1)
            return dp[str][i];
        string t = "";
        
        // Try each prefix of the string 
        for (int j = i; j < n; ++j) {
            t += words[str][j];
            
            // If it's in wordsSet and not the same as words[str],
            // try to check the remaining suffix.
            if (wordsSet.find(t) != wordsSet.end() && t != words[str]) {
                bool ans = isConcat(str, j + 1);
                if (ans) {
                    dp[str][i] = true;
                    return true;
                }
            }
        }
        
        // Not a concatenation
        dp[str][i] = false;
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words) {
            wordsSet.insert(word);
        }
        this->words = words;
        dp.resize(words.size());
        for (int i = 0; i < words.size(); ++i)
            dp[i].resize(words[i].size(), -1);
        
        // Check each word if it's a concatenation.
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] != "" && isConcat(i, 0))
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};
