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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode * curr=root;
        int cnt=0;
        int ans = -1;
        while( curr ){
          if(!curr->left){
            cnt++;
            if(cnt == k) ans = curr->val;
            curr=curr->right;
          }
          else{
            TreeNode * prev = curr;
            prev=prev->left;
            while(prev->right&& prev->right != curr) prev=prev->right;
            if( prev -> right == curr){
              cnt++;
              if(cnt==k) ans=curr->val;
              curr=curr->right;
              prev->right=nullptr;
            }
            else if(prev -> right == nullptr){
              prev->right=curr;
              curr=curr->left;
            } 
          }
        }
        return ans; 
    }
};