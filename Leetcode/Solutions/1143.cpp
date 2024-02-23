class Solution {
public:
    int findSubseq(string text1,string text2,int idx1,int idx2 , vector<vector<int>> &dp){
        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2] !=-1){
            return dp[idx1][idx2]; 
        }
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + findSubseq(text1,text2,idx1-1,idx2-1,dp);
        }

        return dp[idx1][idx2]=max(findSubseq(text1,text2,idx1-1,idx2,dp) , findSubseq(text1,text2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int> (n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i] == text2[j]){
                    if(!(i-1>=0 && j-1>=0)){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    continue;
                }
                int s1=0;
                if(i-1>=0){
                    s1+=dp[i-1][j]; 
                }
                int s2=0;
                if(j-1>=0){
                    s2+=dp[i][j-1];
                }
                dp[i][j] = max(s1,s2);
            }
        }
        // int ans = findSubseq(text1,text2,m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};