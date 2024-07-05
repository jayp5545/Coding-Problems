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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int lastValidIdx=-1;
        int firstIdx=-1;
        int index=1;
        ListNode *oriHead = head->next;
        int prev = head->val;
        int cnt=0;
        int minDis=INT_MAX;
        while(oriHead->next){
            if((oriHead->val > prev) && (oriHead->val > oriHead->next->val) || (oriHead->val < prev) && (oriHead->val < oriHead->next->val)){
                if(lastValidIdx != -1){
                     minDis=min(minDis,index-lastValidIdx);
                }else{
                    firstIdx=index;
                }
                cnt++;
                lastValidIdx=index;
            }
            index++;
            prev=oriHead->val;
            oriHead=oriHead->next;
        }
        if(cnt<2) return {-1,-1};
        return {minDis,lastValidIdx-firstIdx}; 
    }
};