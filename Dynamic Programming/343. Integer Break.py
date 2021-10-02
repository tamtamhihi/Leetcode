# https://leetcode.com/problems/integer-break/

class Solution:
    def integerBreak(self, n: int) -> int:
        # dp[i] = maximum product for i >= 2
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        
        # For each number i
        for i in range(2, n+1):
            # Try breaking into 2 parts: j and i-j
            for j in range(1, i):
                # Each calling the dp[j] and dp[i-j]
                # Note that since we have already divided i into 2 parts,
                # each of these part could be a single number (j or i-j)
                # so we take max(dp[j], j) and max(dp[i-j], i-j)
                dp[i] = max(dp[i], max(dp[j], j) * max(dp[i - j], i - j))
        return dp[n]
