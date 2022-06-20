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
        if(root == NULL)return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<Node*> v;
            for(int i = 0; i < sz; i++){
                Node* curr = q.front();
                q.pop();
                v.push_back(curr);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            for(int i = 0; i < v.size(); i++){
                if(i == sz-1)v[i]->next = NULL;
                else v[i]->next = v[i+1];
            }
        }
        
        return root;
    }
};