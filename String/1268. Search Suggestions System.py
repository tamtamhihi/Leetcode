# https://leetcode.com/problems/search-suggestions-system/

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        # Check if b starts with a
        def startsWith(a, b):
            if len(b) < len(a):
                return False
            for i in range(len(a)):
                if a[i] != b[i]:
                    return False
            return True
        
        # Sort the products in increasing lexicographic order
        products.sort()
        
        n = len(searchWord)
        results = [[] for _ in range(n)]
        prefix = ''
        index = 0
        
        for i in range(n):
            # Find the 3 smallest lexicographic that starts with prefix
            prefix += searchWord[i]
            
            # Find the first product that is larger or equal to prefix
            while index < len(products) and products[index] < prefix:
                index += 1
            
            # No more product
            if index == len(products):
                break
            
            # Find at most 3 product
            for j in range(index, min(index + 3, len(products))):
                if startsWith(prefix, products[j]):
                    results[i].append(products[j])
                else:
                    break

        return results
