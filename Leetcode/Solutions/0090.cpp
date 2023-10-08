class Solution {
public:
    void generateSubsets(vector<int> nums,int index,vector<int> &ds,vector<vector<int>> &ans){
      if(index==nums.size()){
        ans.push_back(ds);
        return;
      }
      ds.push_back(nums[index]);
      generateSubsets(nums,index+1,ds,ans);
      ds.pop_back();
      while(index+1<nums.size() && nums[index]==nums[index+1]){
      index=index+1;
      } 
      generateSubsets(nums,index+1,ds,ans);
      return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        generateSubsets(nums,index,ds,ans);
        return ans;
    }
};