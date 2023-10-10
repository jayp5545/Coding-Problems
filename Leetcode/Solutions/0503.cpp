class Solution {
public:
 vector<int> findnge(vector<int> nums){
   int n=nums.size();
   vector<int> ans(n);
   stack<int> st;
   for(int i=0;i<2*n;i++){
     while(!st.empty() && nums[i%n]>nums[st.top()]){
       ans[st.top()]=nums[i%n];
       st.pop();
     }
     if(i<n){
     st.push(i%n);
     }
   }
   while(!st.empty()){
     ans[st.top()]=-1;
     st.pop();
   }
   return ans;
 }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge=findnge(nums);
        return nge;
    }
};