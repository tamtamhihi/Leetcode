class Solution {
public:
    
    // If 2 strings are anagram of each other, their sorted versions
    // will be the same.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        
        // Map a sorted string to an index in <ans>.
        unordered_map<string, int> mp; //parentToAnsInd;
        
        for (int i = 0; i < n; ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.count(s)) {
                ans[mp[s]].push_back(strs[i]);
            } else {
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
                mp[s] = ans.size() - 1;
            }
        }
        
        return ans;
    }
};
