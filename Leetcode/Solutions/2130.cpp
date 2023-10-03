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
    ListNode * reverse1(ListNode *head){
      ListNode * curr=head;
      ListNode * prev=NULL;
      ListNode * forw=NULL;
      while(curr!=NULL){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
      }
      return prev;
    }
    int pairSum(ListNode* head) {
        ListNode * temp=head;
        ListNode *fast=head;
        ListNode * slow=head;
        while(fast!=NULL && fast->next !=NULL){
          fast=fast->next->next;
          slow=slow->next;
        }
        ListNode *reversedSecondHalf =reverse1(slow);
        ListNode  * start=head;
        int maxSum=INT_MIN;
        ListNode* secondhalf=reversedSecondHalf;
        while(secondhalf!=NULL){
          int sum=start->val+secondhalf->val;
          maxSum=max(maxSum,sum);
          start=start->next;
          secondhalf=secondhalf->next;
        }
        return maxSum;
    }
};