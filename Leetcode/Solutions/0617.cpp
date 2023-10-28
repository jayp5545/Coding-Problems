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
    TreeNode *  solve(TreeNode *  root1, TreeNode * root2){
      if(!root1 && !root2) return nullptr;
      TreeNode * node;
      if(!root1){
        node = new TreeNode(root2 -> val);
      }
      else if(!root2){
         node = new TreeNode(root1 -> val);
      }
      else {
         node = new TreeNode( root1->val + root2->val);
      }
      node -> left = solve((root1) ? root1-> left : nullptr, (root2) ? root2-> left : nullptr);
      node -> right = solve((root1) ? root1->right : nullptr,(root2) ?root2->right : nullptr);
      return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if(!root1) return root2;
      if(!root2) return root1;
      if(!root1 && !root2 ) return nullptr;
        TreeNode * ans= solve(root1,root2);
        return ans;
    }
};