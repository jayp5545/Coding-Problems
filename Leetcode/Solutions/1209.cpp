class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans;
        for(int i=0;i<s.size();i++){
          if(!st.empty() && st.top().first==s[i]){
          st.top().second++;class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> v(26,0);
        stack<char> stack;
        for(int i=0;i<s.size();i++){
          if(!stack.empty() && stack.top()==s[i] && v[s[i]-'a']==k-1){
            for(int i=0;i<k-1;i++){
              if(stack.empty()) break;
              stack.pop();
            }
            // while(!stack.empty() && stack.top()==s[i]) 
          }
          else {
            if(!stack.empty() && stack.top()!=s[i]) v[s[i]-'a']=1;
            else v[s[i]-'a']++;
            stack.push(s[i]);   
          }
        }
        string ans;
        while(!stack.empty()){
          ans=stack.top()+ ans;
          stack.pop();
        }
        return ans;
    }
};
          if(!st.empty() && st.top().second==k) st.pop();
          }
          else st.push({s[i],1});
        }
        while(!st.empty()){
          string temp="";
          for(int i=0;i<st.top().second;i++){
            temp+=st.top().first;
          }
          ans=temp+ans;
          st.pop();
        }
        return ans;
    }
};