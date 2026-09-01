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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* Pnode = NULL;
        ListNode* Cnode = head;
        ListNode* Nnode = Cnode->next;

        while(Nnode != NULL){
            Cnode->next = Pnode;
            Pnode = Cnode;
            Cnode = Nnode;
            Nnode = Nnode->next;
        }

        Cnode->next = Pnode;
        head = Cnode;
        return head;
    }
};