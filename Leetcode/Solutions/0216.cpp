class Solution {
public:
 void solve(int val,int target,int k,vector<int> &ds,vector<vector<int>> &ans){
   if(val==10){
     if(ds.size()==k && target==0){
       ans.push_back(ds);
     }
     return;
   }
   if(target>=val){
   ds.push_back(val);
   solve(val+1,target-val,k,ds,ans);
   ds.pop_back();
   }
   solve(val+1,target,k,ds,ans);
 }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int val=1;
        solve(val,n,k,ds,ans);
        return ans;
    }
};