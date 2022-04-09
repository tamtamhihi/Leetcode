# https://leetcode.com/problems/product-of-array-except-self/

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Find the product of all nums, except for 0.
        # Keep count of number 0.
        prod = 1
        zero_count = 0
        zero_ind = -1
        results = [0] * len(nums)
        
        for i in range(len(nums)):
            num = nums[i]
            if num != 0:
                prod *= num
            else:
                zero_count += 1
                zero_ind = i
                # If more than 1 zero, all results will be 0
                if zero_count > 1:
                    return results
                
        # If only 1 zero, the position with zero will be prod,
        # the rest will be zero.
        if zero_count == 1:
            results[zero_ind] = prod
            return results
        return [prod // num for num in nums]
