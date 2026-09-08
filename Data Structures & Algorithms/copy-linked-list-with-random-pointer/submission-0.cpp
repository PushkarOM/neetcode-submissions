/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Optimal is to store the copy node inbetween each node
        // then apply the same logic as map, to map each node

        // create copies of node and inserte between
        Node* temp = head;

        while(temp != nullptr){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        if (head == nullptr)
            return nullptr;

        temp = head;

        // copying the random ptr
        while(temp != nullptr){
            temp->next->random = temp->random == nullptr ? nullptr : temp->random->next;
            temp = temp->next->next;
        }

        // copy the next pointers

        temp = head;
        Node* newHead = temp->next;
        Node* temp2 = newHead;
        while(temp != nullptr){
            temp->next = temp->next->next;

            if(temp2->next){
                temp2->next = temp2->next->next;
            }

            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;
    
    }
    
};