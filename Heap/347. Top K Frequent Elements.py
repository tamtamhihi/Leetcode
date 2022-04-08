# https://leetcode.com/problems/top-k-frequent-elements/

from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        for num in nums:
            count[num] += 1
        distinct = list(count.keys())
        distinct.sort(key=lambda key : count[key], reverse=True)
        return distinct[:k]
