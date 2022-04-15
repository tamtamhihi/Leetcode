# https://leetcode.com/problems/path-with-minimum-effort/

from queue import PriorityQueue

# Dijkstra but dist function = minimum effort so far.
# Effort so far = maximum abs difference on the path.

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        r = len(heights)
        c = len(heights[0])
        
        di = [-1, 1, 0, 0]
        dj = [0, 0, -1, 1]
        pq = PriorityQueue()
        
        dist = [[10 ** 9 for _ in range(c)] for _ in range(r)]
        dist[0][0] = 0
        pq.put((0, 0, 0))
        
        while len(pq.queue) > 0:
            dif, i, j = pq.get()
            if i == r-1 and j == c-1:
                return dif
            if dif != dist[i][j]:
                continue
            for k in range(4):
                ni = i + di[k]
                nj = j + dj[k]
                if ni in range(r) and nj in range(c):
                    new_dif = max(dif, abs(heights[ni][nj] - heights[i][j]))
                    if dist[ni][nj] > new_dif:
                        pq.put((new_dif, ni, nj))
                        dist[ni][nj] = new_dif
