class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> temp;
        int i=0;
        int j=0;
        int ans=0;
        int maxFreq=0;
        while(j<s.size()){
          temp[s[j]]++;
          maxFreq = max(maxFreq, temp[s[j]]);
          if(((j-i+1)-maxFreq)<=k){
            ans=max(ans,j-i+1); 
          }
          else{
            temp[s[i]]--;
            i++;
          }
          j++;
        }
        return ans;
    }
};