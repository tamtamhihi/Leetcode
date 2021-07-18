from queue import Queue

class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        di = [-1, 0, 0, 1]
        dj = [0, -1, 1, 0]
        
        si, sj = None, None
        target = 0
        
        # Find the starting position (fill it with '.')
        # and find all keys needed to get
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '@':
                    si, sj = i, j
                    grid[i] = grid[i][:j] + '.' + grid[i][j+1:]
                elif grid[i][j] in 'abcdef':
                    key = ord(grid[i][j]) - ord('a')
                    target = target | (1 << key)
        
        # A state includes the current position, 
        # the acquired keys, and the remained unlocked locks
        q = Queue()
        q.put((si, sj, 0, target))
        memo = set()
        memo.add((si, sj, 0, target)) # Save visited states
        step = 0
        
        # Use BFS to find shortest path to any state that acquires all keys
        while len(q.queue) > 0:
            size = len(q.queue)
            for _ in range(size):
                i, j, keys, unlocked = q.get()
                for k in range(4):
                    ni, nj = i + di[k], j + dj[k]
                    if ni in range(m) and nj in range(n):
                        # Normal cells
                        if grid[ni][nj] == '.' and (ni, nj, keys, unlocked) not in memo:
                            q.put((ni, nj, keys, unlocked))
                            memo.add((ni, nj, keys, unlocked))
                        # Key cells
                        elif grid[ni][nj] in 'abcdef':
                            # Add key to list of acquired keys
                            new_key = ord(grid[ni][nj]) - ord('a')
                            new_keys = keys | (1 << new_key)
                            if new_keys == target:
                                return step + 1
                            if (ni, nj, new_keys, unlocked) not in memo:
                                q.put((ni, nj, new_keys, unlocked))
                                memo.add((ni, nj, new_keys, unlocked))
                        # Lock cells
                        elif grid[ni][nj] in 'ABCDEF':
                            needed_key = ord(grid[ni][nj]) - ord('A')
                            # If we have the corresponding key
                            if (keys >> needed_key) & 1:
                                # Unlock this lock
                                new_unlocked = unlocked & ~(1 << needed_key)
                                if (ni, nj, keys, new_unlocked) not in memo:
                                    q.put((ni, nj, keys, new_unlocked))
                                    memo.add((ni, nj, keys, new_unlocked))
            step += 1
        return -1
