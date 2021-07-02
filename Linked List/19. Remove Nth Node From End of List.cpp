/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* remove(ListNode* current, int& order) {
        if (current == nullptr)
            return nullptr;
        
        ListNode* next = remove(current->next, order);
        
        // Remove current node.
        if (order == 1) {
            order = 0;
            return next;
        }
        
        // The desired node is before this node.
        if (order > 0) {
            --order;
            return current;
        }
        
        // Desired node is already removed.
        current->next = next;
        return current;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return remove(head, n);
    }
};
