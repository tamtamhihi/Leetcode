/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Return 2 values representing total money
    // in subtree rooted at <root>. The first value
    // is robbing at root's house, while the second
    // value is not including the root's house.
    pair<int, int> robbing(TreeNode* root) {
        if (root == nullptr)
            return make_pair(0, 0);
        
        pair<int, int> left = robbing(root->left);
        pair<int, int> right = robbing(root->right);
        
        // If we want to rob root's house, the left and
        // right child cannot be robbed.
        int robbed = root->val + left.second + right.second;
        
        // If we don't rob at root's house, the left and
        // right child can both be robbed, or not.
        int not_robbed = max(left.first, left.second) + max(right.first, right.second);
        
        return make_pair(robbed, not_robbed);
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = robbing(root);
        return max(ans.first, ans.second);
    }
};
