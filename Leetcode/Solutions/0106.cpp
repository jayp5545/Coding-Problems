/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;te
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * constuctTree(vector<int> & inorder,int inStart,int inEnd, vector<int> & postorder,int postStart,int postEnd,  unordered_map<int , int > &inOrderMap) {

      if(inStart > inEnd || postStart > postEnd ) return nullptr;
      TreeNode * root = new TreeNode(postorder[postEnd]);

      int idx = inOrderMap[postorder[postEnd]];
      int nElem = idx - inStart;

      root -> left = constuctTree(inorder,inStart,idx-1,postorder,postStart,postStart + nElem - 1,inOrderMap );
          root -> right  = constuctTree(inorder,idx+1,inEnd,postorder, postStart + nElem,postEnd-1,inOrderMap);

      return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int > inOrderMap;
        for(int i=0;i< inorder.size();i++){
          inOrderMap[inorder[i]]=i;
        }
        int inStart=0; int inEnd=inorder.size()-1;
        int postStart=0; int postEnd=postorder.size()-1;
        TreeNode * root = constuctTree(inorder,inStart,inEnd,postorder,postStart,postEnd,inOrderMap);

        return root;
    }
};