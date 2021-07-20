class Solution:
    # The key idea is to find the longest prefix
    # that is a palindrome. We reverse s and find
    # the longest prefix of s that is the suffix 
    # of the reversed string.
    
    # Ex: s = 'aabaac', r = 'caabaa'
    # Longest prefix of s that is suffix of r
    # is 'aabaa'
    
    def shortestPalindrome(self, s: str) -> str:
        # Use polynomial hashing
        KEY = 37
        MOD = 10 ** 9 + 7
        n = len(s)
        power = [1] * (n+1)
        
        # Precalculate powers of key
        for i in range(1, n+1):
            power[i] = (power[i-1] * KEY) % MOD
        
        # Return the hashed array of a string
        def hashing(strg):
            l = len(strg)
            hashed = [0] * (l+1)
            for i in range(l):
                hashed[i+1] = (hashed[i] * KEY + ord(strg[i]) - ord('a') + 1) % MOD
            return hashed
        
        # Get the polynomial hash of a substring
        def getHash(hashed, left, right): # 1-indexed
            return (hashed[right] - hashed[left-1] * power[right-left+1]) % MOD
        
        # Hash s and its reversed string
        hashedS = hashing(s)
        hashedR = hashing(s[len(s)::-1])
        
        ans = 0
        # For each length of prefix of s, find if it's also
        # the suffix of reversed string
        for i in range(1, n+1):
            if getHash(hashedS, 1, i) == getHash(hashedR, n-i+1, n):
                ans = i
        
        # We reverse n-ans characters of s
        rev = s[ans:]
        rev = rev[len(rev)::-1]
        return rev + s 
