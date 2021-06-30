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

// Since the default priority_queue in C++ is max heap,
// we implement operator so that ListNodes with smaller values
// are considered to be "larger".
struct option {
    bool operator() (ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, option> pq;
        
        // Add all nodes to priority_queue.
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        
        ListNode* head = nullptr, *ans = nullptr;
        
        while (!pq.empty()) {
            // Pop the ListNode with the smallest value and append it to ans.
            ListNode* cur = pq.top();
            pq.pop();
            
            if (ans == nullptr) {
                head = cur;
                ans = cur;
            }
            else {
                ans->next = cur;
                ans = ans->next;
            }
            
            // If there remains nodes after this smallest ListNode,
            // we continue adding it to the priority queue.
            cur = cur->next;
            if (cur != nullptr)
                pq.push(cur);
        }
        return head;
    }
};
