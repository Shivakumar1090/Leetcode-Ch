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
    void paths(TreeNode* root,string ds,vector<string> &ans){
        if(root == NULL)return;
        if(!root->left && !root->right){
            ds+=to_string(root->val);
            ans.push_back(ds);
            return;
        }
        
        ds += to_string(root->val);
        ds += "->";
        paths(root->left,ds,ans);
        paths(root->right,ds,ans);
        
        ds.pop_back();
        // ds.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds;
        vector<string> ans;
        paths(root,ds,ans);
        return ans;
    }
};