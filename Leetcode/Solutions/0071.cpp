class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<string> stack;
        for(int i=0;i<path.size();i++){
          if(path[i]=='/'){
            string temp;
            i++;
            while(path[i]!='/'){
            temp+=path[i];i++;
            }
            if(temp==".."){
              if(!stack.empty()) stack.pop();
            }
            else if(temp=="."){
              continue;
            }
            else stack.push(temp);
            i--;
            }
        }
         if(stack.empty()) return "/";
          while(!stack.empty()){
            string temp1="";
            temp1+='/';
            temp1+=stack.top();
            ans=temp1+ans;
            stack.pop();
          }
      return ans;
        // }
    }
};