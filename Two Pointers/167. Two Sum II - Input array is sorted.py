# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        # Use 2 pointers
        while left < right:
            # The only exact solution
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
            # The sum is too large, needs to decrease 1 number (right)
            if numbers[left] + numbers[right] > target:
                right -= 1
            # The sum is too small, needs to increase 1 number (left)
            else:
                left += 1
