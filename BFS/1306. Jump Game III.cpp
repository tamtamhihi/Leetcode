class Solution {
public:
    
    // Use BFS idea to find if from start node, we can reach any node
    // with value = 0.
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
            return true;
        
        int n = arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        
        int u, v;
        
        while (q.empty() == false) {
            u = q.front();
            q.pop();
            
            // The neighbor node of u is u + arr[u] or u - arr[u]
            for (int e = -1; e <= 1; e += 2) {
                v = u + arr[u] * e;
                
                if (v >= 0 && v < n && visited[v] == false) {
                    if (arr[v] == 0)
                        return true;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return false;
    }
};
