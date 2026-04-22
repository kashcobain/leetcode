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
    int findlen(ListNode* head)
    {
         ListNode* curr=head;
        int cnt=1;
        while(curr->next)
        {
            curr=curr->next;
            cnt++;

        }
        curr->next=head;
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(head==nullptr || k==0)
        {
            return head;

        }
        int n=findlen(head);
         k=k%n;
        for(int i=0;i<n-k-1;i++)
        {
            curr=curr->next;

        }
         ListNode* newHead = curr->next;
         curr->next = NULL;
         return newHead;


        
    }
};