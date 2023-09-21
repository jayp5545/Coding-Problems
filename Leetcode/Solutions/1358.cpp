TC:O(N)
SC:O(3)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int ans=0;
        unordered_map<int,int> counts;
        int i=0;
        int j=0;
        while(j<s.size()){  
          counts[s[j]]++;
          while(counts.size()==3){
            ans+=s.size()-j;
            counts[s[i]]--;
            if(counts[s[i]]==0) counts.erase(s[i]);
            i++;
          }
          j++;
       }
       return ans;
    }
};