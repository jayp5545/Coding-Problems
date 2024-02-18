class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size();
        unordered_map<char,int> temp;

        for(int i=0;i<s.size();i++){
            temp[s[i]]++;
        }
        int maxFreq=0;
        for(auto it:temp){
            maxFreq=max(maxFreq,it.second);
        }
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(temp.find(s[i]) != temp.end()){
                if(temp[s[i]] == maxFreq){
                    ans.push_back(s[i]);
                    temp[s[i]]--; // Impo step
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};