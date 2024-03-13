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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * dummy = new ListNode(1);
        dummy->next=head;
        unordered_map<int,ListNode*> temp;
        temp.insert({0,dummy});
        int preSum=0;
        while(head!=nullptr){
            preSum += head->val;
            if(temp.find(preSum) != temp.end()){
                ListNode * curr = temp[preSum];
                ListNode * node = curr->next;
                int pSum = preSum;
                while(node!=head){
                    pSum += node->val;
                    temp.erase(pSum);
                    node=node->next;
                }
                curr->next=head->next;
                head=head->next;
                continue;
            }
            temp[preSum] = head;
            head=head->next;
        }
        return dummy->next;
    }
};