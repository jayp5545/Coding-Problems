/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> st;
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty()){
          int size=st.size();
          vector<int> val1;
          for(int i=0;i<size;i++){
            TreeNode * temp=st.front();
            st.pop();
            if(temp->left!=NULL) st.push(temp->left);
            if(temp->right!=NULL) st.push(temp->right);
            val1.push_back(temp->val);
          }
          ans.push_back(val1);
        }
        return ans;

    }
};