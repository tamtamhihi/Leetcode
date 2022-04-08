# https://leetcode.com/problems/find-median-from-data-stream/

from queue import PriorityQueue

class MedianFinder:
    def __init__(self):
        # Let n be the current member count.
        
        # max heap keeping the smaller (n+1) / 2 elements
        self.smaller = PriorityQueue()
        
        # min heap keeping the larger n / 2 elements
        self.larger = PriorityQueue() # min-heap

    def addNum(self, num: int) -> None:
        # if 2 heaps are equal in size
        # then we try to increase the size of <smaller>
        if len(self.smaller.queue) == len(self.larger.queue):
            if len(self.larger.queue) == 0:
                self.smaller.put(-num)
            else:
                # comparing the incoming <num> and the smallest in <larger>,
                # one of them will be joining <smaller>, and one to <larger>
                a = self.larger.queue[0]
                if a < num:
                    self.larger.get()
                    self.smaller.put(-a)
                    self.larger.put(num)
                else:
                    self.smaller.put(-num)
        # otherwise, try to increase the size of <larger>
        # so that they are equal in size
        else:
            self.smaller.put(-num)
            a = -self.smaller.get()
            self.larger.put(a)

    def findMedian(self) -> float:
        # If 2 heaps are equal in size, we average 2 values:
        # max of <smaller> and min of <larger>
        if len(self.smaller.queue) == len(self.larger.queue):
            a = -self.smaller.queue[0]
            b = self.larger.queue[0]
            return (a+b) / 2
        # otherwise, we take the max of <smaller>
        else:
            return -self.smaller.queue[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
