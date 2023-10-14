class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> v(26, -1);
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = i;
        }
        vector<bool> inStack(26, false); // to keep track of characters in stack
        for (int i = 0; i < s.size(); i++) {
            if (inStack[s[i] - 'a']) {
                continue; // skip if character is already in the stack
            }
            while (!st.empty() && s[i] < st.top() && v[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            inStack[s[i] - 'a'] = true;
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
