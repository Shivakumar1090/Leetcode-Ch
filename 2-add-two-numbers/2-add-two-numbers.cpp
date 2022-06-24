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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        int prev = 0;
        
        while(l1 != NULL && l2 != NULL){
            int val = l1->val+l2->val;
            if(prev >= 1){
                val += prev;
                prev = 0;
            }
            if(val >= 10){
                prev = 1;
                val = val%10;
            }
            temp -> next = new ListNode(val);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int val = l1->val;
            if(prev >= 1){
                val += prev;
                prev = 0;
            }
            if(val >= 10){
                prev = 1;
                val = val%10;
            }
            temp -> next = new ListNode(val);
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int val = l2->val;
            if(prev >= 1){
                val += prev;
                prev = 0;
            }
            if(val >= 10){
                prev = 1;
                val = val%10;
            }
            temp -> next = new ListNode(val);
            temp = temp->next;
            l2 = l2->next;
        }
        
        if(prev >= 1)temp->next = new ListNode(prev);
        
        return ans->next;
    }
};