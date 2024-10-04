class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans=1e9;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%p;
        }
        int target = sum % p;
        if(target == 0) return 0;
        unordered_map<long long,int> preSum;
        long long sum1=0;
        for(int i=0;i<n;i++){
            sum1=(sum1+nums[i])%p;
            if(sum1 == target){
                ans=min(ans,i+1);
            }
            long long findSum = (sum1-target+p)%p;
            if(preSum.find(findSum) != preSum.end()){
                ans=min(ans,i-preSum[findSum]);
            }
            preSum[sum1]=i;
        }
        if(ans==n) return -1;
        return (ans==1e9) ? -1 : ans;
    }
};