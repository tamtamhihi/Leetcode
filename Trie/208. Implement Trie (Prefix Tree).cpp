class Trie {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isWord;
        TrieNode() {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
            isWord = false;
        }
    };
    
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int ch = c - 'a';
            if (cur->child[ch] == nullptr)
                cur->child[ch] = new TrieNode();
            cur = cur->child[ch];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int ch = c - 'a';
            if (cur->child[ch] == nullptr)
                return false;
            cur = cur->child[ch];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int ch = c - 'a';
            if (cur->child[ch] == nullptr)
                return false;
            cur = cur->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
