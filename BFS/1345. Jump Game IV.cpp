class Solution {
public:
    // We use the idea of BFS here.
    // At each index u, the "neighbors" are:
    // - Index v such that arr[u] = arr[v]
    // - u+1 or u-1
    
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> graph;
        int n = arr.size();
        
        // We store indices that share the same value
        // in a hashed map. For consecutive indices
        // that have same value, we only care about
        // the first and last index only.
        // Ex: 1 7 7 7 7 7 7 2
    
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
            while (i+1 < n && arr[i] == arr[i+1]) {
                ++i;
            }
            graph[arr[i]].push_back(i);
        }
        
        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        
        while (q.empty() == false) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[arr[u]].size(); ++i) {
                int v = graph[arr[u]][i];
                if (u != v && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if (u-1 >= 0 && dist[u-1] == -1) {
                dist[u-1] = dist[u] + 1;
                q.push(u-1);
            }
            if (u+1 < n && dist[u+1] == -1) {
                dist[u+1] = dist[u] + 1;
                q.push(u+1);
            }
        }
        
        return dist[n-1];
    }
};
