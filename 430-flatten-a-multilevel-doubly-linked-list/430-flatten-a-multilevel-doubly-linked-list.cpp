/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            if(temp->child != NULL){
                Node* copy = temp->child;
                temp->child = NULL;
                Node* last , *travel = copy;
                
                while(travel->next != NULL){
                    travel = travel->next;
                }
                last = travel;
                
                Node* next = temp->next;
                if(next)next->prev = NULL;
                
                temp->next = copy;
                copy->prev = temp;
                
                last->next = next;
                if(next)next->prev = last;
            }
            temp = temp->next;
        }
        
        return head;
    }
};