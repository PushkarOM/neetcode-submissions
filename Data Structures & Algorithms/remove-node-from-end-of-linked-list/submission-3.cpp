class Solution {

    // Keep fast n nodes ahead of slow.
    // Move both until fast reaches the end;
    // slow lands just before the node to delete.
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Create a gap of n nodes
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both while maintaining the gap
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is now just before the node to delete
        slow->next = slow->next->next;

        return dummy->next;
    }
};