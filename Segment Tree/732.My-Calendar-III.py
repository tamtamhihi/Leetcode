# https://leetcode.com/problems/my-calendar-iii/

from collections import defaultdict

# Imagine an array where arr[i] = the number of events that occupy at hour i.
# Whenever we book an event [start, end), we increase arr[start], ..., arr[end-1] by 1.
# The maximum number of k is max(arr).

# We will use a segment tree to quickly update the range [start, end)
# and query the max of arr.

class MyCalendarThree:
    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)
        self.MAX = 10 ** 9
    
    def update(self, index, left, right, fr, to, val):
        if left > right:
            return
        if self.lazy[index] > 0:
            self.tree[index] += self.lazy[index]
            if left != right:
                self.lazy[2 * index + 1] += self.lazy[index]
                self.lazy[2 * index + 2] += self.lazy[index]
            self.lazy[index] = 0
        if to < left or fr > right:
            return
        if fr <= left and right <= to:
            self.tree[index] += val
            if left != right:
                self.lazy[2 * index + 1] += val
                self.lazy[2 * index + 2] += val
            return
        mid = (left + right) // 2
        self.update(2 * index + 1, left, mid, fr, to, val)
        self.update(2 * index + 2, mid+1, right, fr, to, val)
        self.tree[index] = max(self.tree[2 * index + 1], self.tree[2 * index + 2])
        
    def book(self, start: int, end: int) -> int:
        self.update(0, 0, self.MAX, start, end-1, 1)
        return self.tree[0]

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
