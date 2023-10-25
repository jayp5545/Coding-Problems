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
    void solve(TreeNode * root,vector<string> & ans , string curr){
      if(root == nullptr) return ;
      curr=curr + to_string(root->val) + "->";
      if( !root -> left && !root-> right){
        ans.push_back(curr.substr(0,curr.size()-2));
        return ;
      }
      solve(root -> left , ans , curr);
      solve(root -> right , ans , curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        // if(root == nullptr ) return ans;
        string curr="";
        solve(root , ans , curr);
        return ans;
    }
};