class Solution:
    def countVowelPermutation(self, n: int) -> int:

        # Each variable stores the number of strings 
        # ending with the corresonding vowels
        
        # If string has 1 character only, the number 
        # of strings is 1
        a, e, i, o, u = 1, 1, 1, 1, 1
        
        # Based on the rules, we iterate through each
        # character and change the count
        for k in range(n-1):
            a, e, i, o, u = e + i + u, a + i, e + o, i, i + o
            
        return (a + e + i + o + u) % (10 ** 9 + 7)
