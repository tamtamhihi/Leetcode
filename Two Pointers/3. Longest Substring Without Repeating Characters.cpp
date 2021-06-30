class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We use a hashed map to keep track if a character
        // has been encountered in [left, right].
        unordered_map<char, bool> ch;
        
        int answer = 0;
        
        // left starts at 0.
        int left = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            
            // If s[right] hasn't appeared in [left, right - 1]
            // then [left, right] is a valid substring.
            if (!ch[s[right]]) {
                ch[s[right]] = true;
            }
            // Else, we have to increase left until we remove
            // the occurence of s[right].
            else {
                while (s[left] != s[right]) {
                    ch[s[left]] = false; // Remember to mark this character unencountered.
                    ++left;
                }
                // Now s[left] == s[right], we increase 1 index
                // to make the new [left, right] valid.
                ++left;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};