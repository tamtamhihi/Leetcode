class Solution {
public:
    // BFS simultaneously from all (i, j) such that mat[i][j] = 0
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int count = 0;
        vector<vector<int>> answer(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    count += 1;
                    answer[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int di[4] = {-1, 0, 0, 1};
        int dj[4] = {0, -1, 1, 0};
        while (q.empty() == false && count < m * n) {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = p.first + di[k];
                int nj = p.second + dj[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && answer[ni][nj] == -1) {
                    answer[ni][nj] = answer[p.first][p.second] + 1;
                    count += 1;
                    if (count == m * n) {
                        return answer;
                    }
                    q.push(make_pair(ni, nj));
                }
            }
        }
        return answer;
    }
};
