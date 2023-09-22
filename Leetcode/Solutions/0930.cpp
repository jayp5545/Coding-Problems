class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        map<int,int> temp;
        int count=0;
        int sum=0;
        temp[0]=1;
        while(j<nums.size()){
          sum+=nums[j];
          if(temp.find(sum-goal)!=temp.end()){
            count+=temp[sum-goal];
          }
          temp[sum]++;
          j++;
        }
        return count;
    }
};