# https://leetcode.com/problems/reverse-pairs/

class FenwickTree:
    def __init__(self, capacity):
        self.capacity = capacity
        self.tree = [0] * (capacity + 1)
    def get(self, index):
        count = 0
        while index > 0:
            count += self.tree[index]
            index -= index & (-index)
        return count      
    def increase(self, index, val):
        while index <= self.capacity:
            self.tree[index] += val
            index += index & (-index)

def get_specific_rank(arr, n):
    sorted_arr = sorted(arr)
    ranks = dict()
    rank = 1
    for i in range(n):
        if i > 0 and sorted_arr[i] == sorted_arr[i-1]:
            continue
        ranks[sorted_arr[i]] = rank
        rank += 1
    return ranks

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Append the double of all values and map each value
        # to a specific rank (1-based).
        # Ex: nums = [2, 3], append [4, 6] --> we have [2, 3, 4, 6]
        # We map: ranks[2] = 1, ranks[3] = 2, ranks[4] = 3, ranks[6] = 4.
        
        nums = nums + [2 * num for num in nums]
        ranks = get_specific_rank(nums, 2 * n)
        
        tree = FenwickTree(2 * n)
        pairs = 0
        
        # Loop original array from the right, find the rank of nums[i].
        # The number of posiitons j making up a reverse pair with i
        # is the number of values with rank smaller than <rank>.
        for i in range(n-1, -1, -1):
            rank = ranks[nums[i]]
            pairs += tree.get(rank - 1)
            # Increase the count of nums[i] * 2 and continue
            # to the left.
            tree.increase(ranks[nums[i] * 2], 1)
        return pairs
