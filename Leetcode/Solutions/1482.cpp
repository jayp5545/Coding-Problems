class Solution {
public:
int checkIsValid(vector<int>& bloomDay,int m ,int k, int mid){
  long long count=0;
  long long noOfBouquets=0;
  cout<<mid;
  for(int i=0;i<bloomDay.size();i++){
    if(bloomDay[i]<=mid) count++;
    else count=0;
    // count+=bloomDay[i];
    if(count==k){
      noOfBouquets++;
      count=0;
    }
    if(noOfBouquets>=m) return 1;
  }
  cout<<noOfBouquets<<endl;
  return 0;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0;
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        cout<<end<<endl;
        if((m*1LL*k)>bloomDay.size()) return -1;
        while(start<=end){
         int mid=start+(end-start)/2;
         cout<<mid<<endl;
         int isValid=checkIsValid(bloomDay,m,k,mid);
         if(isValid){
         ans=mid;
         end=mid-1;
         }
         else start=mid+1; 
        }
        return ans;
    }
};