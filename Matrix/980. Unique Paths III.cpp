class Solution {
public:
    int count, si, sj, di, dj, m, n;
    long target;
    int DI[4] = {-1, 0, 0, 1};
    int DJ[4] = {0, -1, 1, 0};

    void dfs(int i, int j, long visited, vector<vector<int>>& grid) {
        // If we reach the final cell
        if (i == di && j == dj) {
            // Increase count only if we have visit all required cells
            if (visited == target)
                count += 1;
            return;
        }
        // We haven't reached the final cell, so no increase
        if (visited == target)
            return;
        
        // Visit current cell.
        visited |= 1 << (i * n + j);
        for (int k = 0; k < 4; ++k) {
            int ni = i + DI[k];
            int nj = j + DJ[k];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && (grid[ni][nj] == 0 || grid[ni][nj] == 2) && (visited >> (ni * n + nj) & 1) == 0) {
                dfs(ni, nj, visited, grid);
            }
        }
        
        // Backtrack
        visited &= ~(1 << (i * n + j));
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // Find source and destination,
        // and mark the required cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    si = i, sj = j;
                    target |= 1 << (i * n + j);
                }
                else if (grid[i][j] == 2)
                    di = i, dj = j;
                else if (grid[i][j] == 0)
                    target |= 1 << (i * n + j);
            }
        }
        count = 0;
        dfs(si, sj, 0, grid);
        return count;
    }
};
