from queue import Queue

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        di = [-1, 0, 0, 1]
        dj = [0, -1, 1, 0]
        m, n = 2, 3
        
        # Convert board into a bitmask, where each cell
        # takes up 3 bits
        initial = 0
        si, sj = None, None
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                initial = (initial << 3) | board[i][j]
                if board[i][j] == 0:
                    si, sj = i, j
        
        # Convert the target into bitmask
        board = [[1, 2, 3], [4, 5, 0]]
        target = 0
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                target = (target << 3) | board[i][j]
        
        step = 0
        q = Queue()
        q.put((si, sj, initial)) # The current 0 position and the current board
        memo = set()
        
        while len(q.queue) > 0:
            size = len(q.queue)
            for _ in range(size):
                i, j, state = q.get()
                pos = (i * n + j) * 3
                if state == target:
                    return step
                for k in range(4):
                    ni, nj = i + di[k], j + dj[k]
                    npos = (ni * n + nj) * 3
                    if ni in range(m) and nj in range(n):
                        # Try to swap cell (i, j) and (ni, nj)
                        value = (state >> npos) & 7 # Take value at (ni, nj)
                        new_state = state & ~(7 << npos) # Swap 0 into (ni, nj)
                        new_state |= value << pos # Copy value to (i, j)
                        if new_state == target:
                            return step + 1
                        if (ni, nj, new_state) not in memo:
                            q.put((ni, nj, new_state))
                            memo.add((ni, nj, new_state))
            step += 1
        return -1
