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
    void inorder(TreeNode* root,int& sum,int &val){
        if(root == NULL){
            return;
        }
        val = val*10+root->val;
        if(root->left == NULL && root->right == NULL){
            sum += val;
            val /= 10;
            return;
        }
        inorder(root->left,sum,val);
        inorder(root->right,sum,val);
        val /=10;
    }
    int sumNumbers(TreeNode* root) {
        int val = 0 , sum = 0;
        
        inorder(root,sum,val);
        return sum;
    }
};