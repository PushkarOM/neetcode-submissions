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
    void reorderList(ListNode* head) {

        ListNode *slow, *fast, *head2;
        
        slow = head;
        fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

    

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        
        slow->next = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;  // save
            curr->next = prev;            // reverse
            prev = curr;                  // move prev
            curr = next;                  // move curr
        }

        head2 = prev;

        // now interleave
        ListNode *temp1, *temp2, *temp3, *temp4;

        temp1 = head;
        temp2 = head2;

        while(temp1 != nullptr && temp2 != nullptr){
                temp3 = temp1->next;
                temp4 = temp2->next;

                temp1->next = temp2;
                temp2->next = temp3;

                temp1 = temp3;
                temp2 = temp4;
        }
    }
};