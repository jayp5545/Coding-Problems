class Solution {
public:
    vector<int> findSLE(vector<int> &arr){
      vector<int> ans;
      stack<int> st;
      for(int i=0;i<arr.size();i++){
        if(st.empty()) ans.push_back(-1);
        else if(!st.empty() && arr[st.top()]<=arr[i]) ans.push_back(st.top());
        else if(!st.empty() && arr[st.top()]>arr[i]){
          while(!st.empty() && arr[st.top()]>arr[i]){
          st.pop();
          }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        }
        st.push(i);
      }
      return ans;
    }

    vector<int> findSRE(vector<int> &arr){
      vector<int> ans;
      stack<int> st;
      for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()) ans.push_back(-1);
        else if(arr[st.top()]<arr[i]) ans.push_back(st.top());
        else if(!st.empty() && arr[st.top()]>=arr[i]){
          while(!st.empty() && arr[st.top()]>=arr[i]){
          st.pop();
          }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        }
        st.push(i);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> sle=findSLE(arr);
        vector<int> sre=findSRE(arr);
        int mod=1e9+7;
        int ans=0;

        for(int i=0;i<arr.size();i++){
          int m,n;
          if(sle[i]==-1) m=i+1;
          else m=i-sle[i];
          if(sre[i]==-1) n=arr.size()-i;
          else n=sre[i]-i;
          cout<<m<<" "<<n<<endl;
          long val=(m*n)%mod;
          long long val1=(val*arr[i])%mod;
          ans=(ans+ val1)%mod;
        }
        return ans;
    }
};