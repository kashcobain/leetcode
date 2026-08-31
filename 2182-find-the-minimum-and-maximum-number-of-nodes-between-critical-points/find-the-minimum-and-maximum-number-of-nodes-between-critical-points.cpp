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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         ListNode* temp=head;
        ListNode* prev=temp;
          ListNode* curr=temp->next;
          ListNode* nxt=curr->next;
       
        int cnt=2;
        vector<int>pos;
        while(curr->next)
        {
            int a=prev->val;
            int b=curr->val;
            int c=nxt->val;
            if(a>b && c>b)
            {

                pos.push_back(cnt);
            }
            else if(a<b && c<b)
            {
                pos.push_back(cnt);
            }
            cnt++;
           prev=curr;
           curr=nxt;
           nxt=nxt->next;

        }
        if(pos.size()<=1)return {-1,-1};
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=1;i<pos.size();i++)
        {
            if(pos[i]-pos[i-1]<mini)
            {
                mini=pos[i]-pos[i-1];
            }



        }
        return {mini,abs(pos[0]-pos[pos.size()-1])};
        
    }
};