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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)return head;
        
        int sz = 1;
        auto temp = head;
        
        while(temp ->next != NULL){
            temp = temp->next;
            sz++;
        }
        
        temp->next = head;
        temp = head;
        
        for(int i = 0; i < sz-(k % sz)-1; ++i){
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = nullptr;
        
        return head;
    }
};