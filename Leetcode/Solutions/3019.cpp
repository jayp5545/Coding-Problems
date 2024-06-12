class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(tolower(s[i]) != tolower(s[i-1])){
                ans++;
            }
        }
        return ans;
    }
};