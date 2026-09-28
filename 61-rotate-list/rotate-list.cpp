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
        int len=1;
        ListNode* temp=head;
        if(head==nullptr)return nullptr;
        while(temp->next)
        {
            temp=temp->next;
            len++;
        }
        temp->next=head;
        k=k%len;
        ListNode* curr=head;
        for(int i=0;i<len-k-1;i++)
        {
            curr=curr->next;
        }
        ListNode* newh=curr->next;
        curr->next=nullptr;
        return newh;

        
    }
};