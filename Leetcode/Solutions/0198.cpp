class Solution {
public:
    void solve(int n,vector<int> &nums,vector<int> &dp){
        for(int i=2;i<dp.size();i++){
          dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);
        }
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        int n=nums.size();
        dp[0]=0;
        dp[1]=nums[0];
        solve(n,nums,dp);
        return dp[n];
    }
};