class Solution:
    # Use KMP algorithm.
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        
        def kmp_preprocess(s: str) -> list:
            n = len(s)
            prefix = [0] * n
            length = 0
            i = 1
            while i < n:
                if s[i] == s[length]:
                    length += 1
                    prefix[i] = length
                    i += 1
                else:
                    if length == 0:
                        prefix[i] = 0
                        i += 1
                    else:
                        length = prefix[length - 1]
            return prefix
                
        prefix = kmp_preprocess(needle)
        
        def kmp(haystack: str, needle: str, prefix: list) -> int:
            i, j = 0, 0
            m, n = len(haystack), len(needle)
            while i < m:
                if haystack[i] == needle[j]:
                    i += 1
                    j += 1
                if j == n:
                    return i - n
                elif i < m and haystack[i] != needle[j]:
                    if j == 0:
                        i += 1
                    else:
                        j = prefix[j-1]
            return -1
        
        return kmp(haystack, needle, prefix)
