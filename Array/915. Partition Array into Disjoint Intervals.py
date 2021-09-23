# https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        # First choose the smallest left possible
        left = 0
        
        # Keeping the maximum of [0, left]
        current_max = nums[0]
        
        # Keeping the maximum of [0, i]
        possible_max = nums[0]
        
        for i in range(1, len(nums) - 1):
            # We must extend <left> to position <i>
            if nums[i] < current_max:
                left = i
                current_max = possible_max # Change the new current_max
            else:
                # Keep track of the maximum
                possible_max = max(possible_max, nums[i])
        
        return left + 1
