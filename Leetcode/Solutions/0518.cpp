class Solution {
public:
    int solve(vector<int>& coins, int index, int amount,
              vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (index == 0) {
            if (amount % coins[index] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int notpick = solve(coins, index - 1, amount, dp);
        int pick = 0;
        if (coins[index] <= amount) {
            pick = solve(coins, index, amount - coins[index], dp);
        }
        return dp[index][amount] = notpick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, n - 1, amount, dp);
        return ans;
    }
};