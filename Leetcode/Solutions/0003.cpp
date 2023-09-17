class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        int i=0;
        int j=0;
        int count=0;
        map<char,int> temp;
        // int val=-1;
        while(j<s.size()){
          temp[s[j]]++;
          if(temp[s[j]]>1){
              // val=1;
              count=max(count,j-i);
              // temp[s[j]]--;
              temp.clear();
              temp[s[j]]++;
              i=j;
          }
          j++;
        }
        // if(val==-1) return 1;
        return count;
    }
};