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
    pair<int,int> solve(TreeNode * root,int &ans){
        pair<int,int> left={-1,-1} ,right={-1,-1};
        if(root->left){
             left = solve(root->left,ans);
        }
        if(root->right){
             right = solve(root->right,ans);
        }
        if(left.first==-1 && right.first==-1){
            return {root->val,root->val};
        }
        else if(left.first==-1){
            int maxVal=max(abs(root->val - right.first),abs(root->val-right.second));
              ans=max(ans,maxVal);
            int mini=min(root->val,right.first);
            int maxi=max(root->val,right.second);
            return {mini,maxi};
        }
        else if(right.first==-1){
            int maxVal=max(abs(root->val - left.first),abs(root->val-left.second));
            ans=max(ans,maxVal);
            int mini=min(root->val,left.first);
            int maxi=max(root->val,left.second);
            return {mini,maxi};
        }
        else{
             ans=max(ans,abs(root->val-left.first));
             ans=max(ans,abs(root->val-left.second));
             ans=max(ans,abs(root->val-right.first));
             ans=max(ans,abs(root->val-right.second));
            int mini1=min(root->val,left.first);
            int mini=min(mini1,right.first);
            int maxi1=max(root->val,left.second);
            int maxi=max(maxi1,right.second);
            return {mini,maxi};
        }
        return {0,0};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        pair<int,int> temp = solve(root,ans);
        return ans;
    }
};