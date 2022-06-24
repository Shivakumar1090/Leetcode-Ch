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
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        int val = 0;
        
        while(l1 != NULL || l2 != NULL){
            // int val = l1->val+l2->val;
            val /= 10;
            if(l1 != NULL){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                val += l2->val;
                l2 = l2->next;
            }
            
            temp -> next = new ListNode(val%10);
            temp = temp->next;
        }
        
        if(val/10 >0)temp->next = new ListNode(1);
        
        return ans->next;
    }
};