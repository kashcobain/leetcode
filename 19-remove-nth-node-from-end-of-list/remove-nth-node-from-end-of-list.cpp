class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        head = rev(head);

        ListNode dummy(0);
        dummy.next = head;

        ListNode* temp = &dummy;

        for (int i = 1; i < n; i++) {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return rev(dummy.next);
    }
};