class Solution {
public:
int checkIfPossible(vector<int> &nums,int k,int mid){
  int sum=0;
  int noOfSubArrays=1;
  for(int i=0;i<nums.size();i++){
    sum+=nums[i];
    if(sum>mid){
      sum=nums[i];
      noOfSubArrays++;
    }
    if(noOfSubArrays>k) return 0;
  }
  return 1;
}
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
        } 
        int end=sum;
        int ans=-1;
        while(start<=end){
          int mid=start+(end-start)/2;
          int ifPossible=checkIfPossible(nums,k,mid);
          if(ifPossible){
            ans=mid;
            end=mid-1;
          }
          else start=mid+1;
        }
        return ans;
    }
};