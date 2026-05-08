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
    ListNode* rev(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&& fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    ListNode* second=rev(slow->next);
    int maxi=INT_MIN;
    while(second)
    {
        maxi=max(maxi,second->val+head->val);
        second=second->next;
        head=head->next;
    }

        return maxi;
    }
};