class Solution:
    # The answer has k digits. If nums1 contribute i digits,
    # then nums2 contribute k-i digits.
    
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        ans = []
        
        # We try with i = 0 to k
        for i in range(k+1):
            j = k - i
            if i > len(nums1) or j > len(nums2):
                continue 
                
            # Find the largest number with i, j digits from nums1, nums2
            n1 = self.getMaxK(nums1, i)
            n2 = self.getMaxK(nums2, j)
            
            # Merge these 2 numbers to get k digits
            n = self.merge(n1, n2)
            
            # Compare with current answer
            if ans < n:
                ans = n
        return ans
    
    # Get maximum k-digit number from nums
    def getMaxK(self, nums, k):
        if k == 0:
            return []
        n = len(nums)
        # Take the first k digits
        a = [nums[i] for i in range(k)]
        
        # For each next digit, we try to find if we can append 
        # this digit to a, and pop 1 exisitng digit out of a
        # to make a larger.
        # To do so, we find out the 1st position smaller than its
        # right neighbor. If that exists, we will remove that
        # position.
        for i in range(k, n):
            a.append(nums[i])
            j = 0
            while j < k:
                if a[j] < a[j+1]:
                    break
                j += 1
            a.pop(j)
        return a
    
    # Merge 2 nums to get maximum number
    def merge(self, nums1, nums2):
        ans = []
        while nums1 and nums2:
            if nums1 > nums2:
                ans.append(nums1[0])
                nums1 = nums1[1:]
            else:
                ans.append(nums2[0])
                nums2 = nums2[1:]
        ans += nums1
        ans += nums2
        return ans
