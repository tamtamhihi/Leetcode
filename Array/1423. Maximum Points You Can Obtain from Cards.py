# https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        # Find the smallest subarray with length n-k
        # The largest points is sum(cardPoints) - min_subarray
        n = len(cardPoints)
        subarray = sum(cardPoints[:n-k])
        min_subarray = subarray
        all_sum = sum(cardPoints)
        for i in range(n-k, n):
            subarray = subarray - cardPoints[i-n+k] + cardPoints[i]
            min_subarray = min(min_subarray, subarray)
        return all_sum - min_subarray
