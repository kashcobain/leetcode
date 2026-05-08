class Solution {
public:

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // create copy
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* curr = head;

        while(curr) {

            temp->next =
                new ListNode(curr->val);

            temp = temp->next;

            curr = curr->next;
        }

       
        ListNode* copied =
            dummy->next;

  
        ListNode* rev =
            reverse(copied);

    
        while(head && rev) {

            if(head->val != rev->val)
                return false;

            head = head->next;
            rev = rev->next;
        }

        return true;
    }
};