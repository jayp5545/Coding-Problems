class Solution {
public:
    int solve(vector<int> &coins,int idx,int amount,int n,vector<vector<int>> &dp){
    
        if(idx==0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notpick = solve(coins,idx-1,amount,n,dp);
        int pick = INT_MAX;
        if( amount >= coins[idx]){
            pick = 1+solve(coins,idx,amount-coins[idx],n,dp);
        }
        return dp[idx][amount] = min(notpick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = solve(coins,n-1,amount,n,dp);
        if( ans ==1e9){
            return -1;
        }
        return ans;
    }
};