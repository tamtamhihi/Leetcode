class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        # We need v letters 'V' and h letters 'H'
        v, h = destination[0], destination[1]
        
        fact = [1] * (v + h + 1)
        for i in range(1, v + h):
            fact[i] = fact[i-1] * i
        
        # Number of strings with numH letters 'H' and numV letters 'V' 
        def numWaysToOrder(numH, numV):
            return fact[numH + numV] // fact[numH] // fact[numV]
        
        ans = ''
        while v > 0 and h > 0:
            # If we append a letter 'H' to ans, there are hWays distinct strings,
            # which means the 1st to hWays-th string.
            hWays = numWaysToOrder(h - 1, v)
            
            # If k > hWays, we must append 'V'
            if k > hWays:
                ans += 'V'
                v -= 1
                k -= hWays
            else:
                ans += 'H'
                h -= 1
        
        while v > 0:
            ans += 'V'
            v -= 1
        while h > 0:
            ans += 'H'
            h -= 1
        
        return ans
