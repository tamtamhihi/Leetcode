class Solution {
public:
    class Node {
    public:
        Node* child[26];
        bool isWord;
        Node() {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
            isWord = false;
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void add(string word) {
            Node* cur = root;
            for (char c : word) {
                int curChar = c - 'a';
                if (cur->child[curChar] == nullptr)
                    cur->child[curChar] = new Node();
                cur = cur->child[curChar];
            }
            cur->isWord = true;
        }
        string getLongestWord() {
            return findLongest(root);
        }
    private:
        string findLongest(Node* node) {
            if (node == nullptr)
                return "";
            string ans = "";
            for (int i = 0; i < 26; ++i) {
                if (node->child[i] != nullptr && node->child[i]->isWord == true) {
                    string temp = char(i + 'a') + findLongest(node->child[i]);
                    if (temp.size() > ans.size())
                        ans = temp;
                }
            }
            return ans;
        }
    };
    string longestWord(vector<string>& words) {
        Trie trie;
        for (string& word : words)
            trie.add(word);
        return trie.getLongestWord();
    }
};
