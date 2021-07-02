class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Coordinate offset going left, down, right, up
        vector<vector<int>> direction = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        
        // Stopping coordinates
        vector<vector<int>> threshold = {
            {0, n-1}, {m-1, n-1}, {m-1, 0}, {1, 0}
        };
        
        // Changes to stopping coordinates once we change direction.
        vector<vector<int>> incre = {
            {1, -1}, {-1, -1}, {-1, 1}, {1, 1}
        };
        
        int i = 0, j = 0, ind = 0, cnt = 0;
        vector<int> ans;
        
        while (cnt < m * n) {
            ans.push_back(matrix[i][j]);
            ++cnt;
            
            // Reaching the stopping coordinates of this direction
            if (i == threshold[ind][0] && j == threshold[ind][1]) {
                threshold[ind][0] += incre[ind][0];
                threshold[ind][1] += incre[ind][1];
                
                // Change direction
                ind = (ind + 1) % 4;
                i += direction[ind][0];
                j += direction[ind][1];
            } else {
                i += direction[ind][0];
                j += direction[ind][1];
            }
        }
        return ans;
    }
};
