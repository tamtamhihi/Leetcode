# https://leetcode.com/problems/path-with-maximum-gold/

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        di = [-1, 0, 0, 1]
        dj = [0, -1, 1, 0]
        memo = dict()
        
        # DFS from cell (i, j) given the bitmask of visited cells.
        # If cell (i, j) is visited, the (i * n + j)-th bit is on.
        # The <state> is for memoization. Without this, we can't simply
        # cache memo[(i, j)].
        def dfs(i, j, state):
            new_state = state | (1 << (i * n + j))
            if (i, j, new_state) in memo:
                return memo[(i, j, new_state)]
            sum_gold = 0
            # Try all directions and find out which direction gives more gold
            for k in range(4):
                ni, nj = i + di[k], j + dj[k]
                if ni in range(m) and nj in range(n) and grid[ni][nj] > 0:
                    if (new_state >> (ni * n + nj)) & 1 == 1:
                        continue
                    sum_gold = max(sum_gold, dfs(ni, nj, new_state))
            memo[(i, j, new_state)] = sum_gold + grid[i][j]
            return sum_gold + grid[i][j]
        
        max_gold = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    max_gold = max(max_gold, dfs(i, j, 0))
        return max_gold
