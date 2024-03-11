class Solution {
public:
    int solve(string &word1,string &word2,vector<vector<int>> &dp,int i,int j){
        if(j<0){
            return i+1;
        }
        if(i<0) return j+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(word1,word2,dp,i-1,j-1);
        }else{
            int a1 = 1 + solve(word1,word2,dp,i-1,j);
            int a2 = 1 + solve(word1,word2,dp,i-1,j-1);
            int a3 = 1 + solve(word1,word2,dp,i,j-1);
            int minTillNow = min(a1,a2);
            return dp[i][j] = min(minTillNow,a3);
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));

        int ans = solve(word1,word2,dp,m-1,n-1);
        return ans;
    }
};