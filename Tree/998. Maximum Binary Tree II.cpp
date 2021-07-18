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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        // Null tree, so we add a new node.
        if (root == nullptr)
            return newNode;
        // If <val> is larger than the whole tree,
        // <newNode> will be the new root, whose
        // left subtree is the current <root>
        if (root->val < val) {
            newNode->left = root;
            return newNode;
        }
        // Else, <val> will be added the <root>'s
        // right subtree (the new right subtree's root
        // might change so we assign it back to root->right)
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
