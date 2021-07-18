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
    int count;
    void traverse(TreeNode* root, int countOdd, vector<int>& curCount) {
        if (root == nullptr)
            return;
        int digit = root->val;
        curCount[digit]++;
        if (curCount[digit] % 2 == 1)
            ++countOdd;
        else 
            --countOdd;
        if (root->left == nullptr && root->right == nullptr) {
            if (countOdd <= 1) {
                count += 1;
            }
        } else {
            traverse(root->left, countOdd, curCount);
            traverse(root->right, countOdd, curCount);
        }
        if (curCount[digit] % 2 == 1)
            --countOdd;
        else 
            ++countOdd;
        curCount[digit]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> curCount(10, 0);
        count = 0;
        traverse(root, 0, curCount);
        return count;
    }
};
