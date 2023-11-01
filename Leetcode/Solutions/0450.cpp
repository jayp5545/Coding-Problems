/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), lefjjmmmmmmmmmmmmmmmmmmmmmjt(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if( root-> val == key){
          return helper(root);
        }
        TreeNode * curr=root;
        while(curr){
          if(key < curr->val){
            if( curr->left && curr -> left -> val ==key){
              curr-> left = helper(curr->left);
              return root;
            }
            else curr=curr->left;
          }
          else{
            if( curr->right &&curr->right -> val == key){
              curr -> right = helper(curr->right);
              return root;
            }
            else curr=curr->right;
          }
        }
        return root;
    }
    TreeNode * helper(TreeNode * root){
      if(!root->left){
        return root->right;
      }
      if(!root->right) return root->left;
      TreeNode * rightNode = root->right;
      TreeNode * leftNode=root->left;
      TreeNode * curr=root->left;
      while(curr->right) curr=curr->right;
      curr->right=rightNode;
      return leftNode;
    }
};