class Solution {
public:
    bool isValid(int noOfCandies,vector<int>& candies,long long k){
         long long cnt=0;
         int n = candies.size();
        for(int j=0;j<n;j++){
            cnt+=(candies[j]/noOfCandies);
        }
            if(cnt>=k) return true;
            return false; 
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int left = 1;
        int right = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(isValid(mid,candies,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};