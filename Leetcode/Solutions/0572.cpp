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
    bool solve(TreeNode * root, TreeNode * subroot){
      if(!root || !subroot) return root == subroot;
      return root-> val == subroot->val && solve(root->left, subroot->left) && solve(root->right , subroot->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if( subRoot == nullptr) return true;
        if(solve(root,subRoot)) return true;
        return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};