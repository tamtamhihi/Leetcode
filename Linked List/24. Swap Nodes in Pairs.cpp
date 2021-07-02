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
    ListNode* swapPairs(ListNode* head) {     
        // Nothing to swap
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Save the new head to return
        ListNode* newHead = head->next;
        
        ListNode* previous = nullptr, *current = head;
        
        // Loop until no more pair to swap
        while (current != nullptr && current->next != nullptr) {
            
            // Swap current and current->next
            ListNode* temp = current->next;
            current->next = temp->next;
            temp->next = current;
            
            // Connect to the previous pair
            if (previous != nullptr) {
                previous->next = temp;
            }
            previous = temp->next;
            
            // Move to next pair
            current = temp->next->next;
        }
        
        // In case the number of nodes is odd.
        if (current != nullptr)
            previous->next = current;
        
        return newHead;
        
        /*
        
        // A recursive solution (4ms).
        
        if (head == nullptr)
            return nullptr;
        ListNode* newHead = head->next;
        if (newHead == nullptr)
            return head;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
        
        */
    }
};
