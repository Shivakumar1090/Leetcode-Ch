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
    void range(TreeNode* root,int l,int h,int &sum){
        if(root == NULL)return;
        if(root->val >= l && root->val <= h)sum += root->val;
        
        if(root->val > l)range(root->left , l , h, sum);
        if(root->val < h)range(root->right,l,h,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        range(root,low,high,sum);
        return sum;
    }
};