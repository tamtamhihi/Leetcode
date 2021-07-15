# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        
        self.ans = 0
        
        # This function returns the longest 
        # STRAIGHT path containing <root>
        def longestPath(root):
            if root == None:
                return 0
            
            # Longest STRAIGHT path of left and right
            leftPath = longestPath(root.left)
            rightPath = longestPath(root.right)
            
            curPath = 1
            
            # Set them to 0 if not same value with root
            if root.left != None and root.left.val != root.val:
                leftPath = 0
            if root.right != None and root.right.val != root.val:
                rightPath = 0
            
            # Update this CURVED path into answer
            self.ans = max(self.ans, leftPath + 1 + rightPath)
            
            # Return the longest STRAIGHT path
            return 1 + max(leftPath, rightPath)
            
            
        longestPath(root)
        
        return self.ans - 1 if self.ans else 0
