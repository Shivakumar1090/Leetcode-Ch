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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head , *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head , *prev = NULL , *next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
         if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        ListNode* mid = getMid(head);
        ListNode* afterMid = mid->next;
        mid->next = NULL;
        
        ListNode* afterMidRev = reverse(afterMid);
        // ListNode* curr = head;
        
        while(afterMidRev != NULL && head!= NULL){
            ListNode* temp = head->next;
            // ListNode* prev = afterMidRev->next;
            head->next = afterMidRev;
            afterMidRev = afterMidRev->next;
            head->next->next = temp;
            head = temp;
        }
    }
};