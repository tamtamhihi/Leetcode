class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        // <prev> is the leftmost non-null node of current level.
        Node* prev = root, *cur, *firstNode;
        
        // In each iteration of this while loop, we try to 
        // populate the whole next level, with the help of 
        // previous level's <prev>.
        while (true) {
            
            // We find the first non-null node of this level,
            // and start populating from this node towards right.
            cur = nullptr;
            
            while (prev != nullptr) {
                if (prev->left != nullptr) {
                    cur = prev->left;
                    break;
                }
                if (prev->right != nullptr) {
                    cur = prev->right;
                    prev = prev->next;
                    break;
                }
                prev = prev->next;
            }
            
            // If no non-null node is found, we stop this while loop.
            if (cur == nullptr)
                break;
            
            // Save the first non-null node of this level for later.
            firstNode = cur;
            
            // Iterating <prev> (previous level)
            while (prev != nullptr) {
                
                // If the left child of this <prev> is not null, and
                // not the same as cur, we assign this left child to
                // be <next> of <cur>.
                if (prev->left != nullptr && prev->left != cur) {
                    cur->next = prev->left;
                    cur = cur->next;
                } 
                
                // ELse if the right child is not null, we assign it to
                // be next. Notice that here, we propagate <prev> because
                // staying here has no use (<cur> has been assigned with
                // current <prev>'s right child).
                else if (prev->right != nullptr && prev->right != cur) {
                    cur->next = prev->right;
                    cur = cur->next;
                    prev = prev->next;
                }
                
                // If both children can't be used, we propagate <prev>.
                else {
                    prev = prev->next;
                }
            }
            
            // Assign firstNode of this level to <prev> to get ready
            // for the next level.
            prev = firstNode;
        }
        return root;
    }
};
