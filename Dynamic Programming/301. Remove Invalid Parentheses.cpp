class Solution {
public:
    unordered_set<string> answer;
    string s;
    
    void helper(string temp, int curOpen, int i, int removedOpen, int removedClose) {
        if (i == s.size()) {
            // No need to remove anything, and no remaining opening tags
            if (curOpen == 0 && removedOpen == 0 && removedClose == 0)
                answer.insert(temp);
            return;
        }
        
        if (s[i] == ')') {
            
            // Add this ')'
            if (curOpen > 0)
                helper(temp + ")", curOpen - 1, i+1, removedOpen, removedClose);
            
            // Remove this ')'
            if (removedClose > 0)
                helper(temp, curOpen, i+1, removedOpen, removedClose - 1);
        
        } 
        
        else if (s[i] == '(') {
            
            // Add this '('
            helper(temp + "(", curOpen + 1, i+1, removedOpen, removedClose);
            
            // Remove this '('
            if (removedOpen > 0)
                helper(temp, curOpen, i+1, removedOpen - 1, removedClose);
        
        } 
        
        else {
            
            // Never remove a character
            helper(temp + s[i], curOpen, i+1, removedOpen, removedClose);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        
        int removeOpen = 0, removeClose = 0;
        int open = 0;
        for (char c : s) {
            if (c == '(')
                ++open;
            else if (c == ')') {
                // Normal --> no need to remove
                if (open > 0)
                    --open;
                // close tag without opening tag
                else 
                    ++removeClose;
            }
        }
        // The remaining opening tags will need to be removed
        removeOpen = open;
        
        helper("", 0, 0, removeOpen, removeClose);
        
        vector<string> res;
        for (string a : answer)
            res.push_back(a);
        
        return res;
    }
};
