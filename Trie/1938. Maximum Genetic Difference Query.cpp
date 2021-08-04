class Solution {
public:
    class Node {
    public:
        Node* child[2];
        int count;
        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
            count = 0;
        }
        bool isLeaf() {
            return (child[0] == nullptr || child[0]->count == 0) && (child[1] == nullptr || child[1]->count == 0);
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(int num) {
            Node* cur = root;
            for (int i = 31; i >= 0; --i) {
                int curBit = (num >> i) & 1;
                if (cur->child[curBit] == nullptr)
                    cur->child[curBit] = new Node();
                cur = cur->child[curBit];
                cur->count += 1;
            }
        }
        void remove(int num) {
            Node* cur = root;
            for (int i = 31; i >= 0; --i) {
                int curBit = (num >> i) & 1;
                cur = cur->child[curBit];
                cur->count -= 1;
            }
        }
        int maxXor(int num) {
            if (root->isLeaf())
                return 0;
            Node* cur = root;
            int xorSum = 0;
            for (int i = 31; i >= 0; --i) {
                int curBit = (num >> i) & 1;
                if (cur->child[curBit ^ 1] != nullptr && cur->child[curBit ^ 1]->count > 0) {
                    xorSum += 1 << i;
                    cur = cur->child[curBit ^ 1];
                } else {
                    cur = cur->child[curBit];
                }
            }
            return xorSum;
        }
    };
    unordered_map<int, vector<vector<int>>> nodeToQuery;
    vector<int> answer;
    vector<vector<int>> graph;
    Trie trie;
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[4] < b[4];
    }
    void dfs(int u) {
        for (vector<int>& query : nodeToQuery[u]) {
            int val = query[1];
            int ind = query[2];
            answer[ind] = max(trie.maxXor(val), val ^ u);
        }
        trie.add(u);
        for (int v : graph[u]) {
            dfs(v);
        }
        trie.remove(u);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
            nodeToQuery[queries[i][0]].push_back(queries[i]);
        }
        int n = parents.size();
        graph.resize(n);
        int root;
        for (int i = 0; i < n; ++ i) {
            if (parents[i] == -1)
                root = i;
            else
                graph[parents[i]].push_back(i);
        }
        answer.resize(queries.size());
        dfs(root);
        return answer;
    }
};
