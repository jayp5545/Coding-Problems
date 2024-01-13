/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(null-ptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void findParent(unordered_map<TreeNode *,TreeNode *> &par, TreeNode* root,TreeNode * &startNode,int start) {
    queue<TreeNode*> que;
    que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            if(node->val == start) startNode=node;
            que.pop();
            if (node->right) {
                par[node->right] = node;
                que.push(node->right);
            }
            if (node->left) {
                que.push(node->left);
                par[node->left] = node;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *,TreeNode *> par;
        TreeNode * startNode;
        findParent(par, root,startNode,start);
        queue<pair<TreeNode * ,int>> que;
        que.push({startNode,0});
        unordered_set<TreeNode*> temp;
        temp.insert(startNode);
        int ans=-1;
        while(!que.empty()){
            TreeNode* node = que.front().first;
            int val = que.front().second;
            ans=max(ans,val);
            que.pop();
            if(node->right && temp.find(node->right)==temp.end()){
                temp.insert(node->right);
                que.push({node->right,val+1});
            }
            if(node->left && temp.find(node->left) == temp.end()){
                temp.insert(node->left);
                que.push({node->left,val+1});
            }
            if(par.find(node)!=par.end() && temp.find(par[node])==temp.end()){
                temp.insert(par[node]);
                que.push({par[node],val+1});
            }
        }
        return ans;
    }
    
};