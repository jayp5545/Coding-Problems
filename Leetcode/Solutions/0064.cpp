class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        dp[n-1][m-1] = grid[n-1][m-1];

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
            int dp1=INT_MAX;
            if(i+1 < n){
                dp1 = dp[i+1][j];
            }
            int dp2=INT_MAX;
            if(j+1 < m){
                dp2 = dp[i][j+1];
            }
            dp[i][j] = min(dp1,dp2) + grid[i][j];
        }
    }
        return dp[0][0];
    }
};