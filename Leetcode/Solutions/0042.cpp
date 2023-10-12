class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int maxL=height[0];
        int maxR=height[n-1];
        int start=0;
        int end=n-1;
        while(start<end){
          if(maxL<=maxR){
            start++;
            maxL=max(maxL,height[start]);
            ans+=maxL-height[start];
          }else{
            end--;
            maxR=max(maxR,height[end]);
            ans+=maxR-height[end];
          }
        }
        return ans;
    }
};