class Solution {
public:
    int findFirstOcc(string word,int n,char ch){
        int idx = -1;
         for(int i=0;i<n;i++){
            if( word[i] == ch){
                idx = i;
                return i;
            }
        }
        return idx;
    }
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int idx = findFirstOcc(word,n,ch);
        if(idx==-1){
            return word;
        }
        string ans  ="";
        for(int i=idx;i>=0;i--){
            ans += word[i];
        }
        for(int i=idx+1;i<n;i++){
            ans+=word[i];
        }
        return ans;
    }
};