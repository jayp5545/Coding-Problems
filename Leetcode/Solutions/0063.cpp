class Solution {
public:
    void solve(vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int m,int n){
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if( i == m-1 && j==n-1){
                    continue;
                }
                long long ways = 0;
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i +1 < m){
                    ways += dp[i+1][j];
                }
                if( j+1 < n){
                    ways += dp[i][j+1];
                }
                dp[i][j] = ways;
            }
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));

        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        solve(obstacleGrid,dp,m,n);
        int ans = dp[0][0];
        return ans;
    }
};