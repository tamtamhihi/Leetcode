# https://leetcode.com/problems/reveal-cards-in-increasing-order/

from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        answer = [-1] * n
        # Use a deque to simulate the process and find the next index in answer
        # to be revealed. We will fill these indices with the sorted deck
        d = deque([i for i in range(n)])
        for i in range(n):
            answer[d.popleft()] = deck[i]
            if len(d) > 0:
                d.append(d.popleft())
        return answer
