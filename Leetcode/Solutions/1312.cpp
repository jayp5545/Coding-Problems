class Solution {
public:
    int LPS(string s,string s1,int i,int j,vector<vector<int>> &dp){
         if(dp[i][j] != -1){
            return dp[i][j];
         }
        if(i==0 || j==0) return 0;
        if(s[i-1] == s1[j-1]){
            return dp[i][j] = 1+LPS(s,s1,i-1,j-1,dp);
        }else{
            return dp[i][j] = max(LPS(s,s1,i-1,j,dp),LPS(s,s1,i,j-1,dp));
        }
        return -1;
    }
    int findLPS(string s,string s1){
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        // return LPS(s,s1,n,n,dp)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == s1[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return n - findLPS(s,s1);
    }
};