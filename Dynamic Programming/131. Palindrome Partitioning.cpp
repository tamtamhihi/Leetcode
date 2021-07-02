class Solution {
public:
    string S;
    int n;
    vector<vector<bool>> palindrome;
    vector<vector<string>> answer;
    vector<string> partitioned;
    
    void partitionString(int left) {
        if (left > n - 1) {
            answer.push_back(partitioned);
            return;
        }
        
        // Try cutting if the left part is a partition.
        for (int cut = left; cut <= n - 1; ++cut) {
            if (palindrome[left][cut]) {
                partitioned.push_back(S.substr(left, cut - left + 1));
                partitionString(cut + 1);
                partitioned.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        S = s;
        
        // Determing each substring is palindrome or not.
        palindrome.resize(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end] && (len <= 2 || palindrome[start+1][end-1]))
                    palindrome[start][end] = true;
            }
        }
        
        partitionString(0);
        
        return answer;
    }
};
