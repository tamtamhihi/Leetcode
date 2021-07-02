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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        
        // We use the idea of BFS to traverse each level.
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> v;
            
            // Pop the whole level to put values into <v>.
            int s = q.size();
            
            for (int i = 0; i < s; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};
