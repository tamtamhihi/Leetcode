class Solution {
public:
    
    // The main idea of the solution is that we will not try partitioning 
    // the string randomly. Instead, we will partition the string from left, 
    // and only try making a cut if the left part is a palindrome. 
    
    // Ex: s = "abac". We try:
    //   1. "a" | "bac" --> "a" | "b" | "ac" --> "a" | "b" | "a" | "c" = 3 cuts
    //   2. "aba" | "c" = 1 cut
    //   Answer = min(1, 3) = 1 cut
    // We don't try making a cut at "ab" | "ac" because "ab" is not a palindrome.
    
    // By doing this, we only take care of cutting suffixes of string s.
    
    int minCut(string s) {
        int n = s.size();
        
        // Let dp[i] = minimum cuts of suffix of s starting at i.
        vector<int> dp(n, 1e9);
        
        // We first determine if any substring is a palindrome.
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        
        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end] && (len <= 2 || palindrome[start+1][end-1]))
                    palindrome[start][end] = true;
            }
        }
        
        // We must find the answer to smaller suffixes first.
        for (int left = n - 1; left >= 0; --left) {
            int len = n - left;
            
            // No cut needs to be done because this suffix is a palindrome itself
            if (palindrome[left][n - 1]) {
                dp[left] = 0;
            } else {
                for (int cut = left; cut < n - 1; ++cut) {
                    // Make a cut here.
                    if (palindrome[left][cut])
                        dp[left] = min(dp[left], 1 + dp[cut + 1]);
                }
            }
        }
        
        return dp[0];
    }
}; 
