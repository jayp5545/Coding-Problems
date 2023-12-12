class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size()==0) return ;
        vector<int> val;
        for(int i=0;i<m;i++){
            val.push_back(nums1[i]);
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n){
          if(val[i] <= nums2[j]){
              nums1[k++] = val[i];
              i++;
         }else{
           nums1[k++] = nums2[j];
           j++;
         }
        }
        while(i<m){
          nums1[k++]=val[i++];
        }
        while(j<n){
          nums1[k++]=nums2[j++];
        }
    }
};