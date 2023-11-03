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
private:
    TreeNode * first;
    TreeNode * prev;
    TreeNode * last;
public:
    void dfs(TreeNode * root){
      if( root ==nullptr) return;
      dfs(root->left);
      if(prev!=nullptr && root->val < prev->val){
        if(!first){
          first=prev;
          last=root;
        }
        else last=root;
      }
      prev=root;
      dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val,last->val);
    }
};