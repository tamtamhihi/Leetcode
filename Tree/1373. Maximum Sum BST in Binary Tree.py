# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        INF = 10 ** 9
        self.ans = 0
        
        # Return the sum, min_value and max_value 
        # of subtree rooted at <root>
        def bst(root):
            if root == None:
                return 0, INF, -INF
            if root.left == None and root.right == None:
                self.ans = max(self.ans, root.val)
                print(root.val, root.val, root.val)
                return root.val, root.val, root.val
            leftSum, leftMin, leftMax = bst(root.left)
            rightSum, rightMin, rightMax = bst(root.right)
            
            if (leftMax >= root.val) or (rightMin <= root.val):
                print(root.val)
                return 0, -INF, INF
            
            myMin, myMax = root.val, root.val
            
            if root.left and leftMin != -INF:
                myMin = leftMin
            if root.right and rightMax != INF:
                myMax = rightMax
            self.ans = max(self.ans, leftSum + root.val + rightSum)
            print(leftSum + rightSum + root.val, myMin, myMax)
            return leftSum + root.val + rightSum, myMin, myMax
        
        bst(root)
        return self.ans
