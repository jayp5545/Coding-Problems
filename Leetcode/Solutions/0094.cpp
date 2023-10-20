class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* curr = root->left;
        while(true) {
            if(curr!=NULL){
              st.push(curr);
              curr=curr->left;
            }
            else{
              if(st.empty()) break;
              ans.push_back(st.top()->val);
              curr=st.top()->right;
              st.pop();
            }
        }
        return ans;
    }
};
