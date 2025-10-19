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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

       
        for (auto it : lists) {
            if (it != nullptr) {
                pq.push(it);
            }
        }

        ListNode dummy(-1);
        ListNode* temp = &dummy;

      
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};
