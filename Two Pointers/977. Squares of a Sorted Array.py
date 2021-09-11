class Solution:
    # Try to find the values closest to 0 in the middle of <nums>
    # and expand to the sides by using 2 pointers to mark the 
    # next negative and positive value.
    
    # Another alternative is starting from the values farthest to 0,
    # shrinking from left and right, and finally reverse the result.
    
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        INF = 10 ** 9
        
        # Try to find the first index with positive value
        # and the last index with negative value.
        negative, positive = n-1, n
        answer = []
        
        for i in range(len(nums)):
            if nums[i] > 0:
                negative, positive = i-1, i
                break
            elif nums[i] == 0:
                answer.append(0)
                negative, positive = i-1, i+1
                break
        
        # Find out the next smallest squared value by moving
        # the 2 pointers: negative and positive.
        while negative >= 0 or positive < n:
            negativeSquare = nums[negative] ** 2 if negative >= 0 else INF
            positiveSquare = nums[positive] ** 2 if positive < n else INF
            if negativeSquare <= positiveSquare:
                answer.append(negativeSquare)
                negative -= 1
            else:
                answer.append(positiveSquare)
                positive += 1
        return answer
