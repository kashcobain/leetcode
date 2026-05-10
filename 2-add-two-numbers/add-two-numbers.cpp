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
        ListNode* h1=l1;
        ListNode* h2=l2;
        int sum=0;
        int carry=0;
        ListNode* dummy=new ListNode();
        ListNode* pointer=dummy;
        while(h1 || h2)
        {
            sum+=carry;
            if(h1)
            {
                sum+=h1->val;
                h1=h1->next;
            }
            if(h2)
            {
                sum+=h2->val;
                h2=h2->next;

            }
           pointer->next=new ListNode(sum%10);
           carry=sum/10;
           sum=0;
           pointer=pointer->next;
          

        }
        if(carry)
        {
            pointer->next=new ListNode(carry);
        }
        return dummy->next;
        
    }
};