# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0
        def sumNum(root, cur):
            if root == None:
                return
            cur = cur * 10 + root.val
            if root.left == None and root.right == None:
                self.ans += cur
                return
            sumNum(root.left, cur)
            sumNum(root.right, cur)
        sumNum(root, 0)
        return self.ans
