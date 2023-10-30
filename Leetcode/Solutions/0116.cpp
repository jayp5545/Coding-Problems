/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(root==nullptr) return nullptr; 
      Node * root1=root;
      queue <Node * > que;
      que.push(root);
      while( !que.empty()) {
        Node * node = que.front();
        if( node -> left) node->left->next=node->right;
        if( node -> next && node -> left ) node->right->next=node->next->left;
        if( node -> left ) que.push(node->left);
        if( node-> right ) que.push( node->right);
        que.pop();
      }
      return root1;
    }
};