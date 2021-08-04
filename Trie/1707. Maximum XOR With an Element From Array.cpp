class Solution {
public:
    class Node {
    public:
        Node* child[2];
        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
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
            }
        }
        int traverse(int num) {
            Node* cur = root;
            int xorSum = 0;
            bool smaller = false;
            for (int i = 31; i >= 0; --i) {
                int curBit = (num >> i) & 1;
                if (cur->child[curBit ^ 1] != nullptr) {
                    xorSum += 1 << i;
                    cur = cur->child[curBit ^ 1];
                } else {
                    cur = cur->child[curBit];
                }
            }
            return xorSum;
        }
    };
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Keep the original order of the query before sorting.
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }
        
        // Sort number increasingly
        sort(nums.begin(), nums.end());
        
        // Sort queries increasingly w.r.t. m_i
        sort(queries.begin(), queries.end(), compare);
        vector<int> ans(queries.size());
        
        Trie trie;
        int i = 0; // index in <nums> to add to trie
        for (auto& query : queries) {
            
            // Only add nums <= m_i
            while (i < nums.size() && nums[i] <= query[1]) {
                trie.add(nums[i]);
                ++i;
            }
            
            // If no nums <= m_i, ans is -1
            if (i == 0)
                ans[query[2]] = -1;
            // Else find in the current trie
            else
                ans[query[2]] = trie.traverse(query[0]);
        }
        return ans;
    }
};
