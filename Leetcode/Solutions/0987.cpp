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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int, map<int,multiset<int>>> temp;
        queue<pair<TreeNode * , pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
          TreeNode * node=q.front().first;
          int ver=q.front().second.first;
          int level=q.front().second.second;
          q.pop();
          temp[ver][level].insert(node->val);
          // temp[dist].push_back(node->val);
          if(node->left!=NULL) q.push({node->left,{ver-1,level+1}});
          if(node->right!=NULL) q.push({node->right,{ver+1,level+1}});
        }

        for (auto& verticalPair : temp) {
            vector<int> level;
            for (auto& levelPair : verticalPair.second) {
                for (int val : levelPair.second) {
                    level.push_back(val);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};