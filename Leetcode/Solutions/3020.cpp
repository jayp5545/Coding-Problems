#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> freqMap;
        for(auto num:nums) freqMap[num]++;
        int ans=INT_MIN;
        for(auto [elem,freq] : freqMap){
            ll x=elem;
            int cnt=0;
            while(freqMap.find(x) != freqMap.end() && freqMap[x]){
                if(x == 1) {cnt+=freqMap[x];break;}
                else if(freqMap[x] >=2 ) cnt+=2;
                else if(freqMap[x] == 1) {cnt+=1; break;}
                if(x > 1e5) break;
                x=x*x;
            }
            ans=max(ans,cnt-(cnt%2==0));

        }
        return ans;
    }
};