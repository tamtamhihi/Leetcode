from queue import PriorityQueue
class Pair:
    # For each pair, we save the sum (to compare) 
    # and index of the element in nums2.
    def __init__(self, pair_sum, nums2_ind):
        self.pair_sum = pair_sum
        self.nums2_ind = nums2_ind
    def __lt__(self, other):
        return self.pair_sum < other.pair_sum

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        pq = PriorityQueue()
        n1, n2 = len(nums1), len(nums2)
        ans = []
        
        # For each element in nums1, try the smallest pair possible
        # containing this element (which is the pair with nums2[0])
        for i in range(n1):
            pq.put(Pair(nums1[i] + nums2[0], 0))
        
        # Finding k pairs with smallest sum
        for i in range(k):
            # If no pair is in the priority queue, we 
            # have produces all possible pairs
            if len(pq.queue) == 0:
                break
            
            # Get the current smallest sum pair
            a = pq.get()
            
            # Retrieve 2 elements and append to ans
            ind2 = a.nums2_ind
            num2 = nums2[ind2]
            num1 = a.pair_sum - num2
            ans.append([num1, num2])
            
            # Try the next smallest pair with num1, which is
            # with nums2[ind2 + 1]
            if ind2 + 1 < n2:
                pq.put(Pair(num1 + nums2[ind2 + 1], ind2 + 1))
        return ans
