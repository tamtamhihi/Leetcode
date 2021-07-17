class Solution {
public:
    vector<int> answer;
    vector<int> nums;
    vector<vector<int>> graph;
    vector<vector<bool>> coprimes;
    
    int gcd(int x, int y) {
        int r;
        while (y != 0) {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }
    
    // node, parent: current node index and its parent's index
    // levels: map a value to its level
    // indices: map a value to its node index
    // level: current level of tree
    void func(int parent, int node, vector<int>& levels, vector<int>& indices, int level) {
        int curVal = nums[node];
        // Find coprimes with largest level.
        for (int i = 1; i <= 50; ++i) {
            if (coprimes[i][curVal] && levels[i] != -1) {
                int index = indices[i], iLevel = levels[i];
                if (answer[node] == -1 || levels[nums[answer[node]]] < iLevel)
                    answer[node] = index;
            }
        }
        
        // Save the previous level and index
        int prevLevel = levels[curVal], prevIndex = indices[curVal];
        
        // For the same value, we only care for the lowest level and index.
        levels[curVal] = level;
        indices[curVal] = node;
        
        // Pass to child nodes.
        for (int v : graph[node]) {
            if (v != parent) {
                func(node, v, levels, indices, level + 1);
            }
        }
        
        // Leave this node and restore the previous level and index.
        levels[curVal] = prevLevel;
        indices[curVal] = prevIndex;
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        answer.resize(n, -1);
        this->nums = nums;
        graph.resize(n);
        for (vector<int>& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        coprimes.resize(55, vector<bool>(55, false));
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; ++j) {
                if (gcd(i, j) == 1) {
                    coprimes[i][j] = true;
                }
            }
        }
        vector<int> levels(55, -1);
        vector<int> indices(55, -1);
        func(-1, 0, levels, indices, 0);
        return answer;
    }
};
