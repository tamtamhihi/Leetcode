# https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # Mark which character has appeared
        appear = set()
        self.ans = 0
        
        # Backtracking the result string, considering arr[index]
        def longest(index, prev_len):
            if index == len(arr):
                self.ans = max(self.ans, prev_len)
                return
            
            # There are 2 options regarding arr[index]
            
            # Option 1: Add arr[index] to the result string.
            # We must make sure adding is suitable
            suitable = True
            for i in range(len(arr[index])):
                char = arr[index][i]
                if char in appear:
                    suitable = False
                    for j in range(i):
                        appear.remove(arr[index][j])
                    break
                appear.add(char)
            if suitable:
                # Make recursive call to the next position
                longest(index + 1, prev_len + len(arr[index]))
                # Then backtrack
                for char in arr[index]:
                    appear.remove(char)
            
            # Option 2: Do not add arr[index]
            longest(index + 1, prev_len)
            
        longest(0, 0)
        return self.ans
