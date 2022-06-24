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
#define pi pair<int,ListNode*>
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)return 0;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i = 0; i < n; i++){
            ListNode* curr = lists[i];
            
            if(curr != NULL){
                pq.push({curr->val , curr});
            }
        }
        
        if(pq.size() == 0)return 0;
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(!pq.empty()){
            ListNode* curr = pq.top().second;
            
            if(curr->next != NULL){
                pq.push({curr->next->val , curr->next});
            }
            
            temp->next = new ListNode(curr->val);
            pq.pop();
            temp = temp->next;
        }
        
        return ans->next;
    }
};