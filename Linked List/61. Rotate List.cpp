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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        
        // Count number of nodes in linked list.
        int count = 0;
        ListNode* current = head;
        ListNode* tail;
        while (current != nullptr) {
            ++count;
            tail = current;
            current = current->next;
        }
        
        k %= count;
        current = head;
        
        // Iterate to the new tail.
        for (int i = 0; i < count - k - 1; ++i) {
            current = current->next;
        }
        
        // Rotate
        tail->next = head;
        head = current->next;
        current->next = nullptr;
        return head;
        
    }
};
