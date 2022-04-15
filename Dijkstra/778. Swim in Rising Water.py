# https://leetcode.com/problems/swim-in-rising-water/

from queue import PriorityQueue

# Dijkstra but dist function = maximum value so far on the path.

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 1:
            return grid[0][0]
        
        di = [-1, 1, 0, 0]
        dj = [0, 0, -1, 1]
        pq = PriorityQueue()
        
        visited = [[False for _ in range(n)] for _ in range(n)]
        visited[0][0] = True
        pq.put((grid[0][0], 0, 0))
  
        while len(pq.queue) > 0:
            time, i, j = pq.get()
            if i == n-1 and j == n-1:
                return time
            for k in range(4):
                ni = i + di[k]
                nj = j + dj[k]
                if ni in range(n) and nj in range(n):
                    new_time = max(time, grid[ni][nj])
                    if not visited[ni][nj]:
                        pq.put((new_time, ni, nj))
                        visited[ni][nj] = True
