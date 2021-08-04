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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums)
            trie.add(num);
        int ans= 0;
        for (int num : nums)
            ans = max(ans, trie.traverse(num));
        return ans;
    }
};
