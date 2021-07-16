# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        # Based on Morris traversal.
        
        # The main idea is that we do not modify the current 
        # node's left and right childs at the first visit (so that
        # the prev (predecessor) at the )
        
        # Instead, we will modify it after the second visit, so
        # the predecessor at first and second visit will remain
        # the same
        node = root
        while node:
            if not node.left:
                node = node.right
            else:
                prev = node.left
                while prev.right and prev.right != node:
                    prev = prev.right
                if not prev.right:
                    # This is the first visit, simply mark
                    # the predecessor and move to node's left subtree
                    prev.right = node
                    node = node.left
                else:
                    # This is the second visit. We flatten
                    # by making node's left child becoming
                    # its right child
                    left_node = node.left
                    right_node = node.right
                    node.left = None
                    node.right = left_node
                    # Node's right child will be appended
                    # to the predecessor of node.
                    prev.right = right_node
                    node = right_node
            
