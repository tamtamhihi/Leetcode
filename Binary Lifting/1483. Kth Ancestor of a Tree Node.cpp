class TreeAncestor {
public:
    int n, ln;
    vector<int> parent;
    vector<vector<int>> logParent;
    vector<vector<int>> graph;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        this->parent = parent;
        // Find maximum power of 2.
        this->ln = 0;
        while ((1 << ln) <= n)
            ++ln;
        --ln;
        
        logParent.resize(n, vector<int>(ln+1, -1));
        
        // Find root and convert to adjacency list for DFS.
        graph.resize(n);
        int root;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1)
                root = i;
            else
                graph[parent[i]].push_back(i);
        }
        dfs(root);
    }
    
    // logParent[u][i] = 2^i -th ancestor of u.
    void dfs(int u) {
        logParent[u][0] = parent[u];
        for (int i = 1; i <= ln; ++i) {
            if (logParent[u][i-1] != -1)
                logParent[u][i] = logParent[logParent[u][i-1]][i-1];
            else break;
        }
        for (int v : graph[u]) {
            dfs(v);
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= ln; ++i) {
            if ((k >> i) & 1) {
                node = logParent[node][i];
                if (node == -1)
                    break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
