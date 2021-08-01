class Solution {
public:
    unordered_map<string, bool> dp;
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        
        // Only 1 character.
        if (n == 1)
            return s1[0] == s2[0];
        
        // Find cache.
        string key = s1 + "_" + s2;
        if (dp.find(key) != dp.end())
            return dp[key];
        
        // Count characters of s1 and s2.
        vector<int> count(26, 0);
        for (int i = 0; i < n; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        
        // If the frequency of characters not the same, 
        // it cannot be scrambled.
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0)
                return false;
        }

        // Try all partititons of string to check.
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) {
                dp[key] = true;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) {
                dp[key] = true;
                return true;
            }
        }
        
        dp[key] = false;
        return false;
    }
};
