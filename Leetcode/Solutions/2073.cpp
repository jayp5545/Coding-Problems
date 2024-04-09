class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int numberOfTickets = tickets[k];
        int ans=numberOfTickets;
        for(int i=0;i<n;i++){
            if(i<k){
                ans+=min(tickets[i],numberOfTickets);
            } 
            if(i>k){
                ans+=min(tickets[i],numberOfTickets-1);
            }
        }
        return ans;
    }
};