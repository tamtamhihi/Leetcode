# Detailed explanation available at 
# https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/1346198/
from queue import Queue

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1:
            return 0
        di = [-1, 0, 0, 1]
        dj = [0, -1, 1, 0]
        
        step = 0
        q = Queue()
        q.put((0, 0, k))
        memo = set()
        
        while len(q.queue) > 0:
            size = len(q.queue)
            for _ in range(size):
                i, j, k = q.get()
                for t in range(4):
                    ni = i + di[t]
                    nj = j + dj[t]
                    if ni in range(m) and nj in range(n):
                        if ni == m-1 and nj == n-1:
                            return step + 1
                        if grid[ni][nj] == 1 and k > 0 and (ni, nj, k-1) not in memo:
                            q.put((ni, nj, k-1))
                            memo.add((ni, nj, k-1))
                        elif grid[ni][nj] == 0 and (ni, nj, k) not in memo:
                            q.put((ni, nj, k))
                            memo.add((ni, nj, k))
            step += 1
        return -1
