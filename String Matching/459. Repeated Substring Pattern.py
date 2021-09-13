class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:        
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
                
        prefix = kmp_preprocess(s)
        n = len(prefix)
        return prefix[n-1] > 0 and prefix[n-1] % (n - prefix[n-1]) == 0
