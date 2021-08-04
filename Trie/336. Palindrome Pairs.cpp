class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        int endIndex;
        vector<int> indices;
        TrieNode() {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
            endIndex = -1;
        }
    };
    class Trie {
    public:
        vector<vector<int>> answer;
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void add(string word, int index) {
            TrieNode* cur = root;
            for (int i = word.size() - 1; i >= 0; --i) {
                int ch = word[i] - 'a';
                if (cur->child[ch] == nullptr)
                    cur->child[ch] = new TrieNode();
                if (isPalindrome(word, 0, i) == true)
                    cur->indices.push_back(index);
                cur = cur->child[ch];
            }
            cur->indices.push_back(index);
            cur->endIndex = index;
        }
        void findPairs(string word, int index) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); ++i) {
                if (cur->endIndex != -1 && cur->endIndex != index && isPalindrome(word, i, word.size() - 1)) {
                    vector<int> ans(2);
                    ans[0] = index;
                    ans[1] = cur->endIndex;
                    answer.push_back(ans);
                }
                int ch = word[i] - 'a';
                if (cur->child[ch] == nullptr)
                    return;
                cur = cur->child[ch];
            }
            for (int ind : cur->indices) {
                if (ind == index)
                    continue;
                vector<int> ans(2);
                ans[0] = index;
                ans[1] = ind;
                answer.push_back(ans);
            }
        }
        vector<vector<int>> getPairs() {
            return answer;
        }
    private:
        bool isPalindrome(string& s, int start, int end) {
            while (start < end && s[start] == s[end]) {
                ++start;
                --end;
            }
            return start >= end;
        }
    };
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.add(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            trie.findPairs(words[i], i);
        }
        return trie.getPairs();
    }
};
