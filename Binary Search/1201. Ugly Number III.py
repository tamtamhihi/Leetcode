# https://leetcode.com/problems/ugly-number-iii/

class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        # Calculate the number of ugly numbers <= num
        def smallerUglyNumber(num):
            aUgly = num // a
            bUgly = num // b
            cUgly = num // c
            abUgly = num // (lcm(a, b))
            acUgly = num // (lcm(a, c))
            bcUgly = num // (lcm(b, c))
            abcUgly = num // (lcm(a, lcm(b, c)))
            return aUgly + bUgly + cUgly - abUgly - acUgly - bcUgly + abcUgly
        
        # Determine if num is an ugly number
        def isUgly(num):
            return num % a == 0 or num % b == 0 or num % c == 0
        
        # Use binary search to find the n-th ugly number
        left, right = 1, 2 * 10**9
        while left <= right:
            mid = (left + right) // 2
            smallers = smallerUglyNumber(mid)
            if smallers == n and isUgly(mid): # found it
                return mid
            elif smallers < n: # current mid is too small
                left = mid + 1
            else: # current mid is too large
                right = mid - 1
