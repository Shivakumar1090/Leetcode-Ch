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
    int length(ListNode* head){
        int l = 0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    int getDecimalValue(ListNode* head) {
        int l = length(head) , ans = 0;
        if(head == NULL)return 0;
        
        while(head != NULL){
            ans += head->val*(pow(2,l-1));
            l--;
            head = head->next;
        }
        return ans;
    }
};