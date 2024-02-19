class Solution {
public:
    void solve(vector<vector<int>> &dp,int m,int n){
        dp[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int noOfPaths=0;
                if(i+1 < m){
                    noOfPaths += dp[i+1][j];
                }
                if(j+1 < n){
                    noOfPaths += dp[i][j+1];
                }
                if(i==m-1 && j==n-1){
                    continue;
                }
                dp[i][j] = noOfPaths;
            }
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        solve(dp,m,n);
        return dp[0][0];
    }
};