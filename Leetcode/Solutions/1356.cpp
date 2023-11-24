class Solution {
public:
    int countBits(int elem){
      int cnt=0;
      while(elem!=0){
        if((elem & 1) > 0 ) cnt++;
        elem= elem >> 1;
      }
      return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
      vector<pair<int,int>> temp;
      vector<int> ans;
      for(int i=0;i<arr.size();i++){
         temp.push_back({countBits(arr[i]),arr[i]});
      }
      sort(temp.begin(),temp.end());
      for(auto it: temp){
        ans.push_back(it.second);
      }  
      return ans;
    }
};