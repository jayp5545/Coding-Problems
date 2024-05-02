class Solution {
public:
    int findMaxK(vector<int>& nums) {
       int n= nums.size();
       unordered_set<int> numSet(nums.begin(),nums.end());
       cout<<numSet.size();
       int ans = INT_MIN;
       for(int i=0;i<n;i++){
            if(nums[i]< 0)  {
                if(numSet.find(abs(nums[i])) != numSet.end()){
                    ans=max(ans,abs(nums[i]));
                }
            }
        }
       return (ans>INT_MIN) ? ans : -1;
    }
};