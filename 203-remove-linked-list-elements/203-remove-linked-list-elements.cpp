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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        
        while(head != NULL){
            if(head->val != val){
                curr->next = new ListNode(head->val);
                curr = curr->next;
            }
            head = head->next;
        }
        
        return ans->next;
    }
};