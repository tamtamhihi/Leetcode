/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";
        string ans = "[";
        
        // Use BFS idea to add each level to the string
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            TreeNode* u = q.front();
            q.pop();
            if (u == nullptr)
                ans += "null,";
            else {
                ans += to_string(u->val);
                ans += ',';
                q.push(u->left);
                q.push(u->right);
            }
        }
        
        // Pop the last ','
        ans.pop_back();
        
        ans += ']';
        return ans;
    }
    
    // Find the next string before meeting the ','
    string findNext(string& data, int& i) {
        if (i >= data.size() - 1)
            return "null";
        string ans = "";
        while (i < data.size() - 1 && data[i] != ',') {
            ans += data[i];
            ++i;
        }
        ++i; // ignore the ','
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;
        int i = 1; // ignore the opening '['
        
        string headData = findNext(data, i);
        int headVal = stoi(headData);
        
        TreeNode* head = new TreeNode(headVal);
        
        // Use BFS idea to place the decoded string to each level
        queue<TreeNode*> q;
        q.push(head);
        while (i < data.size() - 1 && q.empty() == false) {
            string left = findNext(data, i);
            string right = findNext(data, i);
            
            TreeNode* cur = q.front();
            q.pop();
            if (left != "null") {
                int leftVal = stoi(left);
                cur->left = new TreeNode(leftVal);
                q.push(cur->left);
            }
            if (right != "null") {
                int rightVal = stoi(right);
                cur->right = new TreeNode(rightVal);
                q.push(cur->right);
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
