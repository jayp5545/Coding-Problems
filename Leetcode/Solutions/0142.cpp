/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow =head;
        bool isCycle=false;
        while(fast && fast->next){
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow){
            isCycle=true;
            break;
          };
        }
        if(!isCycle) return NULL;
        fast=head;
        while(fast!=slow){
          fast=fast->next;
          slow=slow->next;
        }
        return slow;
    }
};