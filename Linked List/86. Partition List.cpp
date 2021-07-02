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
    ListNode* partition(ListNode* head, int x) {
        
        // We maintain 2 linked list of values smaller, and not smaller than x.
        ListNode* smallHead = nullptr, *smallTail = nullptr;
        ListNode* largeHead = nullptr, *largeTail = nullptr;
        
        // We iterate through each node and append it to 1 of the linked lists.
        ListNode* cur = head;
        
        while (cur != nullptr) {
            if (cur->val < x) {
                if (smallHead == nullptr) {
                    smallHead = cur;
                    smallTail = cur;
                } else {
                    smallTail->next = cur;
                    smallTail = cur;
                }
            } else {
                if (largeHead == nullptr) {
                    largeHead = cur;
                    largeTail = cur;
                } else {
                    largeTail->next = cur;
                    largeTail = cur;
                }
            }
            cur = cur->next;
        }
        
        // Free large tail because it's the end of final linked list
        if (largeTail != nullptr)
            largeTail->next = nullptr;
        
        // Connect 2 linked lists.
        if (smallTail != nullptr) {
            smallTail->next = largeHead;
        } else {
            smallHead = largeHead;
        }
        
        return smallHead;
    }
};
