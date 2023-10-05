class Solution {
public:
void solve(int total,int open,int clo,string output,vector<string> &ans){
  if(total==0){
    ans.push_back(output);
    return;
  }
  if(open<clo && open!=0){
    solve(total-1,open-1,clo,output+'(',ans);
    solve(total-1,open,clo-1,output+')',ans);
  }else if(open!=0){
    solve(total-1,open-1,clo,output+'(',ans);
  }else{
    solve(total-1,open,clo-1,output+')',ans);
  }
}
    vector<string> generateParenthesis(int n) {
        int total=n*2;
        total--;
        int open=n;
        int clo=n;
        open--;
        string output="";
        output.push_back('(');
        vector<string> ans;
        solve(total,open,clo,output,ans);
        return ans;
    }
};