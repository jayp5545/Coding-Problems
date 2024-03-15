class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int postProd=1;
        for(int i=n-1;i>=0;i--){
            ans[i] = postProd;
            postProd*=nums[i];
        }

        int preProd=1;
        for(int i=0;i<n;i++){
            int val = preProd * ans[i];
            ans[i]=val;
            preProd*=nums[i];
        }
        return ans;
    }
};