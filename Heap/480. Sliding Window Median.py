# https://leetcode.com/problems/sliding-window-median/

from queue import PriorityQueue
from collections import defaultdict

# This solution is a follow-up of 295. Find Median from Data Stream.
# Besides <add> function, this problem requires <remove> function
# to delete an element out of window but still maintain 2 heaps.

# The solution is lazy removal: instead of actually removing an element
# from the heap, we push it to a <removed> heap.
# But when do we actually delete them from the heap?
# --> Whenever we want to retrieve the top value from the actual heap, 
# we will pop out the values that are equal to the ones in <removed> 
# (a.k.a actually removing them)

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        smaller = PriorityQueue() # max-heap for smaller part
        smaller_removed = PriorityQueue() # max-heap: removed values in smaller part
        
        larger = PriorityQueue() # min-heap for the larger part
        larger_removed = PriorityQueue() # min-heap: removed values in larger part
        
        self.balance = 0    # equals size(smaller) - size(larger)
                            # acceptable values: 0, 1
        
        # Actually pop out removed values
        def lazy_remove(pq, pq_removed):
            while len(pq_removed.queue) > 0 and pq_removed.queue[0] == pq.queue[0]:
                pq.get()
                pq_removed.get()
        
        # Rebalance to make self.balance = 0 or 1
        def rebalance():
            while self.balance > 1:
                lazy_remove(smaller, smaller_removed)
                a = -smaller.get()
                larger.put(a)
                self.balance -= 2
            while self.balance < 0:
                lazy_remove(larger, larger_removed)
                a = larger.get()
                smaller.put(-a)
                self.balance += 2
        
        # Remove a num
        def remove(num):
            # Compare it with the max value of <smaller>
            # to figure out which part it resides
            lazy_remove(smaller, smaller_removed)
            a = -smaller.queue[0]
            if num <= a:
                smaller_removed.put(-num)
                self.balance -= 1
            else:
                larger_removed.put(num)
                self.balance += 1
        
        # Add a num, assuming 2 heaps are balanced
        def add(num):
            if self.balance == 0:
                lazy_remove(larger, larger_removed)
                if len(larger.queue) == 0:
                    smaller.put(-num)
                else:
                    a = larger.queue[0]
                    if a < num:
                        smaller.put(-a)
                        larger.get()
                        larger.put(num)
                    else:
                        smaller.put(-num)
                self.balance = 1
            else:
                lazy_remove(smaller, smaller_removed)
                a = -smaller.queue[0]
                if a > num:
                    larger.put(a)
                    smaller.get()
                    smaller.put(-num)
                else:
                    larger.put(num)
                self.balance = 0
        
        # Get median from the 2 heaps
        def get_median():
            lazy_remove(smaller, smaller_removed)
            lazy_remove(larger, larger_removed)
            if self.balance == 0:
                a = -smaller.queue[0]
                b = larger.queue[0]
                return (a+b) / 2
            return -smaller.queue[0]
        
        # The first window
        for i in range(k):
            add(nums[i])
        res = [get_median()]
        
        # Slide the window, each step removing 1 and adding 1
        for i in range(k, len(nums)):
            remove(nums[i-k])
            rebalance()
            add(nums[i])
            res.append(get_median())
        
        return res
