class TrieNode:
    def __init__(self):
        self.child = [None] * 26
        self.isWord = False
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def add(self, word):
        cur = self.root
        for c in word:
            ch = ord(c) - ord('a')
            if cur.child[ch] == None:
                cur.child[ch] = TrieNode()
            cur = cur.child[ch]
        cur.isWord = True
    def findRoot(self, word):
        cur = self.root
        root = ""
        for c in word:
            ch = ord(c) - ord('a')
            if cur.child[ch] == None:
                return word
            root += c
            cur = cur.child[ch]
            if cur.isWord == True:
                return root
        return root if cur.isWord else word

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for word in dictionary:
            trie.add(word)
        ans = []
        words = sentence.split(' ')
        for word in words:
            ans.append(trie.findRoot(word))
        return ' '.join(ans)
