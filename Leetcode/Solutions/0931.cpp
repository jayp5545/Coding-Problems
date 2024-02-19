class Solution {
public:
    void solve(vector<vector<int>> & dp,vector<vector<int>> & matrix,int n){
        for(int k=0;k<n;k++){
            dp[0][k] = matrix[0][k];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int val = INT_MAX;
                if(j+1 < n){
                    val = min(val ,  dp[i-1][j+1]);
                }
                if( j > 0){
                    val = min(val ,  dp[i-1][j-1]);
                }
                val = min(val ,  dp[i-1][j]);
                if(val==INT_MAX){
                    dp[i][j] = matrix[i][j];
                }
                dp[i][j] = matrix[i][j] + val;
            }
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {       
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        solve(dp,matrix,n);
        int ans= INT_MAX;
        for(int k=0;k<n;k++){
            ans=min(ans,dp[n-1][k]);
        }
        return ans;
    }
};