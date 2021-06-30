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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // result is the Head of the sum
        ListNode* result = nullptr, * current = nullptr;
        int remainder = 0, sum = 0, l1Val, l2Val;
        
        // We only stop when both l1, l2 are nullptr(s), and remainder is 0.
        while (l1 != nullptr || l2 != nullptr || remainder) {
            l1Val = l1 ? l1->val : 0;
            l2Val = l2 ? l2->val : 0;
            sum = remainder + l1Val + l2Val;
            
            if (sum >= 10) {
                remainder = 1;
                sum -= 10;
            } else {
                remainder = 0;
            }
            
            if (result == nullptr) {
                result = new ListNode(sum);
                current = result;
            }
            else {
                current->next = new ListNode(sum);
                current = current->next;
            }
            
            // Only move l1, l2 when it's not nullptr.
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        return result;
    }
};