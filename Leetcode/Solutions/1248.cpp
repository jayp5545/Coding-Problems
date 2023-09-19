class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> temp;
        int oddCount=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]%2==1) oddCount++;
          if(oddCount==k) ans++;
          if(temp.find(oddCount-k)!=temp.end()){
            ans+=temp[oddCount-k];
          }
          temp[oddCount]++;
        }
        return ans;
    }
};