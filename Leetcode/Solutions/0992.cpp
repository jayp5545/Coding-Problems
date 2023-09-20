class Solution {
public:
    int countAtMost(vector<int> &nums,int k){
      int i=0;
      int j=0;
      int count=0;
      unordered_map<int,int> counts;
      while(j<nums.size()){
        counts[nums[j]]++;
          while(counts.size()>k){
            counts[nums[i]]--;
            if(counts[nums[i]]==0) counts.erase(nums[i]);
            i++;
          }
        count+=(j-i+1);
        j++;
      }
      return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1=countAtMost(nums,k);
        int count2=countAtMost(nums,k-1);
        cout<<count1<< " "<<count2;
        return count1-count2;
    }
};