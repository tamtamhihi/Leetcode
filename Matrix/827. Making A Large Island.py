class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visited = [[-1 for _ in range(n)] for _ in range(n)]
        di = [-1, 0, 0, 1]
        dj = [0, -1, 1, 0]
        sizes = []
        
        def findGrid(i, j, num):
            count = 1
            visited[i][j] = num
            for k in range(4):
                ni = i + di[k]
                nj = j + dj[k]
                if ni in range(n) and nj in range(n) and visited[ni][nj] == -1 and grid[ni][nj] == 1:
                    count += findGrid(ni, nj, num)
            return count
        
        ans = 0
        # Find all 1 islands
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and visited[i][j] == -1:
                    size = findGrid(i, j, len(sizes))
                    ans = max(ans, size)
                    sizes.append(size)
        
        # For each 0 grid cell, try filling this cell with 1
        # and compute total size
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    numIsland = []
                    size = 1
                    for k in range(4):
                        ni = i + di[k]
                        nj = j + dj[k]
                        if ni in range(n) and nj in range(n) and grid[ni][nj] == 1 and visited[ni][nj] not in numIsland:
                            size += sizes[visited[ni][nj]]
                            numIsland.append(visited[ni][nj])
                    ans = max(ans, size)
        return ans
