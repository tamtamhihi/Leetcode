# https://leetcode.com/problems/search-suggestions-system/

class Node:
    def __init__(self):
        self.child = [None] * 26
        self.is_word = False

class Trie:
    def __init__(self):
        self.root = Node()
    def add_word(self, word):
        cur_node = self.root
        for char in word:
            ch = ord(char) - ord('a')
            if cur_node.child[ch] == None:
                cur_node.child[ch] = Node()
            cur_node = cur_node.child[ch]
        cur_node.is_word = True
    
    def three_smallest_suggestion(self, node, accumulated_str):
        answer = []
        if node.is_word:
            answer.append(accumulated_str)
        for i in range(26):
            if node.child[i] != None:
                ch = chr(ord('a') + i)
                child_ans = self.three_smallest_suggestion(node.child[i], accumulated_str + ch)
                answer += child_ans
                if len(answer) >= 3:
                    break
        return answer if len(answer) <= 3 else answer[:3]
    
    def find_suggestions(self, word):
        n = len(word)
        answer = [[] for _ in range(n)]
        cur_node = self.root
        prefix = ''
        
        for i in range(n):
            prefix += word[i]
            ch = ord(word[i]) - ord('a')
            if cur_node.child[ch] != None:
                answer[i] = self.three_smallest_suggestion(cur_node.child[ch], prefix)
                cur_node = cur_node.child[ch]
            else:
                break
        return answer
        
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie = Trie()
        for product in products:
            trie.add_word(product)
        return trie.find_suggestions(searchWord)
