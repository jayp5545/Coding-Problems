class Solution {
public:
    string reverseWords(string s) {
        string ans=s;
        reverse(ans.begin() ,ans.end());
        int i=0,l=0,r=0;
        while(i<s.size()){
          while(i< ans.size() && ans[i]!= ' '){
            ans[r++] = ans[i++];
          }
          if( l< r){
            reverse(ans.begin() + l ,ans.begin() + r);
            ans[r++]=' ';
            l=r;
          }
          i++;
        }
        return ans.substr(0,r-1);
    }
};