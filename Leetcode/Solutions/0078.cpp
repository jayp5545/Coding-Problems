class Solution {
public:
void solve(string input,vector<int> output,vector<vector<int>> &ans){
  if(input.size()==0){
    ans.push_back(output);
    return;
  }
  char val=input[0];
  output.push_back(val-'0');
  solve(input.substr(1),output,ans);
  output.pop_back();
  solve(input.substr(1),output,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        string input="";
        for(int i=0;i<nums.size();i++){
          input.push_back(nums[i]+'0');
        }
        vector<int> output;
        vector<vector<int>> ans;
        solve(input,output,ans);
        return ans;
    }
};