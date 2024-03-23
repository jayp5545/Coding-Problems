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
    ListNode * findMidNode(ListNode * head,ListNode * &prevNode){
        ListNode * fast=head;
        ListNode * slow = head;
        while(fast!= nullptr && fast->next != nullptr){
            fast=fast->next->next;
            prevNode=slow;
            slow=slow->next;
        }       
        return slow;
    }
    ListNode * reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode * next=curr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head->next == nullptr){
            return;
        }
        ListNode * prevNode = nullptr;
        ListNode * midNode = findMidNode(head,prevNode);
        ListNode * curr1=head;
        ListNode * curr2 = reverseList(midNode);
        prevNode ->next=nullptr;
        ListNode * last=head;    
        
        while(curr1 && curr2){
            ListNode *next1=curr1->next;
            ListNode *next2 = curr2->next;
            curr2->next=nullptr;
            curr1->next=curr2;
            curr2->next=next1;
            last=curr2;
            curr1=next1;
            curr2=next2;
        }     
        while(curr2){
            last->next=curr2;
            curr2=curr2->next;
        }
    }
};