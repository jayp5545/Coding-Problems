class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if( n < 2){
            return 0;
        }
        int sum=nums[0]+nums[1];
        int operations=1;
        for(int i=2;i<n-1;i+=2){
            if(nums[i] + nums[i+1] == sum){
                operations++;
            }
            else{
                break;
            }
        }
        return operations;
    }
};