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
        if(head == NULL || head->next == NULL)return head;
        map<int ,int> mp;
        
        while(head != NULL){
            mp[head->val]++;
            head = head->next;
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* t = ans;
        
        for(auto it: mp){
            if(it.second == 1){
                ListNode* curr = new ListNode(it.first);
                t->next = curr;
                t = t->next;
            }
        }
        
        return ans->next;
    }
};