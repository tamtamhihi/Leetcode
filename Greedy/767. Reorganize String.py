import queue

# Always append characters with most occurences to result string.
# Make sure 2 adjacent characters are not the same.

# Consisting of the character and the number of occurences.
class Char:
    def __init__(self, ch, count):
        self.ch = ch
        self.count = count
    # Intended to create a max heap in terms of number of occurences
    def __lt__(self, other):
        return self.count > other.count

class Solution:
    def reorganizeString(self, s: str) -> str:
        # Count the number of occurences of each character
        cnt = {chr(ord('a') + i) : 0 for i in range(26)}
        for char in s:
            cnt[char] += 1
        pq = queue.PriorityQueue()
        for i in cnt:
            if cnt[i] != 0:
                pq.put(Char(i, cnt[i]))
        
        ans = ''
        
        # Append the character with most occurences
        lastChar = pq.get()
        lastChar.count -= 1
        ans += nextChar.ch
        
        # Find the next char from heap.
        while len(pq.queue) > 0:
            nextChar = pq.get()
            ans += nextChar.ch
            nextChar.count -= 1
            
            # Put last char back to heap
            if lastChar.count > 0:
                pq.put(lastChar)
            
            
            lastChar = nextChar
        
        if lastChar.count == 0:
            return ans
        return ''
