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
    // We return 3 ListNode*(s): Head, Tail, Next
    vector<ListNode*> reverse(ListNode* cur, int k, int maxK) {
        vector<ListNode*> result(3, nullptr);
        
        // The left-out part.
        if (cur == nullptr) {
            return result;
        }
        
        // The k-th node of each group to be reversed
        if (k == 1) {
            // cur is both Head and Tail of this group
            result[0] = result[1] = cur;
            // reverse the next group and save in Next
            result[2] = reverse(cur->next, maxK, maxK)[0];
            return result;
        }
        
        // Now we're somewhere in the middle (or beginning) of the group
        
        // Reverse the current group.
        vector<ListNode*> subResult = reverse(cur->next, k - 1, maxK);
        
        // If the returned Tail is nullptr, this group is the left-out part.
        // (else the Tail mustn't be nullptr because we're in the middle of group)
        // Hence, no reversing is done.
        if (subResult[1] == nullptr) {
            result[0] = cur;
            result[1] = nullptr;
            result[2] = nullptr;
            return result;
        }
        
        // Now, we're reversing this group.
        
        // Same Head.
        result[0] = subResult[0];
        
        // Alter old Tail and save the new Tail.
        subResult[1]->next = cur;
        result[1] = cur;
        
        if (k != maxK) {
            // If not the first node in group,
            // Next remains the same.
            result[2] = subResult[2];
        } else {
            // Else we append Next to this first node and
            // Next became nullptr
            cur->next = subResult[2];
            result[2] = nullptr;
        }
        return result;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k, k)[0];
    }
};