class Solution {
public:
    void solve(vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                long long ans=INT_MAX;
                if(i+1 <n){
                    ans=min(ans,(long long)dp[i+1][j]);
                    ans=min(ans,(long long)dp[i+1][j+1]);
                }
                if(ans != INT_MAX){
                      dp[i][j] = ans + triangle[i][j];
                }
                else{
                    dp[i][j] = triangle[i][j];
                }
            }
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        solve(triangle,dp,n);
        return dp[0][0];
    }
};