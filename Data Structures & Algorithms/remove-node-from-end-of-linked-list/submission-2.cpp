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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // nth node from end is just kth node from start ie
        // len of list - n = k, kth node is to be found.

        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            len++;
        }

        int k = len - n - 1;
        
        temp = head;
        
        if(k < 0){
            temp = temp->next; 
            head = temp;   
        }
        else{
            while(k>0){
                temp = temp->next;
                k--;
            }
            temp->next = temp->next != nullptr ? temp->next->next : nullptr;
        }


        return head;
    }
};
