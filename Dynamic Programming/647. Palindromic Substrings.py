# https://leetcode.com/problems/palindromic-substrings/

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        
        # dp[i][j] = True if s[i:j] (inclusive) is a palindrome
        dp = [[False for _ in range(n)] for _ in range(n)]
        
        count = 0
        
        # Checking all possible substrings, start from the smallest length
        for length in range(1, n+1):
            for left in range(n - length + 1):
                right = left + length - 1
                
                # Check if the substring is palindrome
                if length == 1:
                    dp[left][right] = True
                elif s[left] == s[right]:
                    if length == 2:
                        dp[left][right] = True
                    else:
                        dp[left][right] = dp[left + 1][right - 1]
                
                # Count palindromes
                if dp[left][right]:
                    count += 1
        return count
