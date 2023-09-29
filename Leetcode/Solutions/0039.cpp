class Solution {
public:
    void solve(vector<int> &candidates,int target,int index,vector<int> &output,vector<vector<int>> & ans,int n){
      if(index==n){
        if(target==0){
          ans.push_back(output);
        }
        return;
      }
        if(target>=candidates[index]){
          output.push_back(candidates[index]);
        solve(candidates,target-candidates[index],index,output,ans,n);
        output.pop_back();
        }
        solve(candidates,target,index+1,output,ans,n);
      }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(candidates,target,index,output,ans,candidates.size());
        return ans;
    }
};