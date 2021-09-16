# https://leetcode.com/problems/patching-array/
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        # This is the smallest number in [0, n] that we haven't achieved.
        # --> We have achieved [0, smallest_missing)
        smallest_missing = 1
        
        index = 0
        added = 0
        
        while smallest_missing <= n:
            
            # If we can find nums[index] <= smallest_missing, we can achieve values
            # [nums[index], nums[index] + 1, ..., nums[index] + smallest_missing)
            # --> The new achieved range is [0, nums[index] + smallest_missing)
            
            if index < len(nums) and nums[index] <= smallest_missing:
                smallest_missing += nums[index]
                index += 1
                
            # Note that a value > smallest_missing won't work because we're 
            # missing out (at least) smallest_missing. 
            # Tf we can't find such value, we must add a new one.
            # The best solution is to add <smallest_missing> itself.
            else:
                smallest_missing += smallest_missing
                added += 1
        
        return added
