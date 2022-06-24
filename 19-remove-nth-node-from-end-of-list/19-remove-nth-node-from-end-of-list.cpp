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
        while(head!=NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0 || head == NULL)return head;
        int len = length(head);
        ListNode* temp = head;
        int count = 1;
        n = len-n;
        if(n == 0)return head->next;
        
        while(temp != NULL){
            if(count == n){
                ListNode* todelete = temp->next;
                // if(temp->next->next)
                temp->next = temp->next->next;
                delete todelete;
                break;
            }
            temp = temp->next;
            count++;
        }
        
        return head;
    }
};