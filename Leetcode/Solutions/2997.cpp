
TC : O(N)
SC : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorOfNums = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int elem = nums[i];
            xorOfNums ^= elem;
        }
        cout<<xorOfNums;
        int xorTotal = k^xorOfNums;
        int ans=0;
        int val = xorTotal;
        cout<<val;
        while(val){
            ans+=(val & 1);
            val = val >> 1;
        }
        return ans; 
    }
};