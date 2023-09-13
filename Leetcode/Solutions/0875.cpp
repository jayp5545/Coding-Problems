
//Time Complexity O(nlog(M))
// Space Complexity O(1)

class Solution {
public:
 bool findValid(vector<int>& piles, int h, int mid) {
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
          hours+=(piles[i]+mid-1)/mid;
          if(hours>h) break;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int maxElement=INT_MIN;
        for(auto it:piles){
          if(it>maxElement) maxElement=it;
        }
        int end=maxElement;
        int ans=-1;
        while(start<=end){
          int mid=start+(end-start)/2;
          bool isValid=findValid(piles,h,mid);
          if(isValid){
            ans=mid;
            end=mid-1;
          }
          else start=mid+1;
        }
        return ans;
    }
};