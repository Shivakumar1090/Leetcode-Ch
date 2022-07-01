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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        if(head == NULL)return NULL;
        
        while(head->next != NULL){
            if(head->next && head->val != head->next->val){
                curr->next = new ListNode(head->val);
                curr = curr->next;
            }
            // curr = curr->next;
            head = head->next;
        }
        
        if(curr->val != head->val){
            curr->next = new ListNode(head->val);
            curr = curr->next;
        }
        
        return ans->next;
    }
};