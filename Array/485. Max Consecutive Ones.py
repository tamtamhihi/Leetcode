class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        answer = 0 # Store the best answer
        streak = 0 # Store the current consecutive streak
        for num in nums:
            if num == 1:
                streak += 1
            else:
                answer = max(answer, streak)
                streak = 0
        # The last streak might not be updated
        return max(answer, streak)
