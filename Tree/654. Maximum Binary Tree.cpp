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
    TreeNode* constructTree(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);
        int maxIndex = left;
        for (int pos = left + 1; pos <= right; ++pos) {
            if (nums[pos] > nums[maxIndex])
                maxIndex = pos;
        }
        TreeNode* node = new TreeNode(nums[maxIndex]);
        node->left = constructTree(nums, left, maxIndex - 1);
        node->right = constructTree(nums, maxIndex + 1, right);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size() - 1);
    }
};
