class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(n%2!=0){
                ans^=nums1[i];
            }
        }
        for(int j=0;j<n;j++){
            if(m%2!=0){
                ans^=nums2[j];
            }
        } 
        return ans;                   
    }
};