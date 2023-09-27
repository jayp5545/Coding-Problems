class Solution {
public:
    int solve(int n,int k){
         if(n==1) return 0;
         int noOfElements=1;
         for(int i=1;i<n;i++){
           noOfElements*=2;
         }
         cout<<noOfElements;
         int mid=noOfElements/2;
         if(k<=mid) return solve(n-1,k);
         else return !(solve(n-1,k-mid));
    }
    int kthGrammar(int n, int k) {
        int ans=solve(n,k);
        return ans;
    }
};