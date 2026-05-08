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

        ListNode* slow = head;
        ListNode* fast = head;

        // correct middle finding
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second =
            reverse(slow->next);

        ListNode* first = head;

        while(second)
        {
            if(second->val != first->val)
            {
                return false;
            }

            second = second->next;
            first = first->next;
        }

        return true;
    }
};