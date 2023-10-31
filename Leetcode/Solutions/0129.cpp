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
    void solve(TreeNode * root, string  s,int &sum){
      if(root == nullptr) return ;
      s.append(to_string(root->val));
      if(!root-> left && !root->right){
        int num = stoi(s);
        cout<<num<<endl;
        sum+=num;
        return ;
      }
      solve(root->left , s , sum);
      solve(root->right , s , sum);
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        int sum=0;
        solve(root,s,sum);
        return sum;
    }
};