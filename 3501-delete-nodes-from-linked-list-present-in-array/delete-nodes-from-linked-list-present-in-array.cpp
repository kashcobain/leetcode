class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur) {
            if (st.find(cur->val) != st.end()) {
                prev->next = cur->next;
                
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
