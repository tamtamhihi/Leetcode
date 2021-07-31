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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int levelHeight = 0;
        while (q.empty() == false) {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            if (levelHeight % 2 == 1)
                reverse(level.begin(), level.end());
            ans.push_back(level);
            levelHeight += 1;
        }
        return ans;
    }
};
