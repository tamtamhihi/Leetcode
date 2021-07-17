from queue import Queue

class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        DI = [-1, 0, 0, 1]
        DJ = [0, -1, 1, 0]
        
        def isValid(i, j):
            return i in range(m) and j in range(n)
        
        # Returns True if from cell (i, j), players can go 
        # to cell (di, dj) given that the box is at cell (bi, bj)
        def canGo(i, j, di, dj, bi, bj):
            if i == di and j == dj:
                return True
            s = [(i, j)]
            visited = [[False for _ in range(n)] for _ in range(n)]
            visited[i][j] = True
            while len(s) > 0:
                i, j = s.pop()
                for k in range(4):
                    ni, nj = i + DI[k], j + DJ[k]
                    if isValid(ni, nj) and not visited[ni][nj] and grid[ni][nj] == '.' and (ni != bi or nj != bj):
                        if ni == di and nj == dj:
                            return True
                        visited[ni][nj] = True
                        s.append((ni, nj))
            return False
        
        # Find final and target position, as well as player's position
        bi, bj, ti, tj, si, sj = None, None, None, None, None, None
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'B':
                    bi, bj = i, j
                    grid[i] = grid[i][:j] + ['.'] + grid[i][j+1:]
                elif grid[i][j] == 'T':
                    ti, tj = i, j
                    grid[i] = grid[i][:j] + ['.'] + grid[i][j+1:]
                elif grid[i][j] == 'S':
                    si, sj = i, j
                    grid[i] = grid[i][:j] + ['.'] + grid[i][j+1:]
        
        # Use BFS to find minimum steps
        step = 0
        q = Queue()
        q.put((bi, bj, si, sj))
        visited = set()
        visited.add((bi, bj, si, sj)) # state including book and player's position
        while len(q.queue) > 0:
            s = len(q.queue)
            for _ in range(s):
                i, j, si, sj = q.get()
                for k in range(4):
                    # To push box from (i, j) to (ni, nj)
                    # player must go to (pi, pj)
                    ni, nj = i + DI[k], j + DJ[k]
                    pi, pj = i - DI[k], j - DJ[k]
                    
                    # If able to push, new box position is (ni, nj),
                    # and new player position is (i, j)
                    if isValid(ni, nj) and isValid(pi, pj) and grid[ni][nj] == '.' and grid[pi][pj] == '.' and (ni, nj, i, j) not in visited and canGo(si, sj, pi, pj, i, j):
                        if ni == ti and nj == tj:
                            return step + 1
                        visited.add((ni, nj, i, j))
                        q.put((ni, nj, i, j))
            step += 1
        return -1
        
