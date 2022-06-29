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
    void dfs(TreeNode* root,int &prev,int &ans){
        if(root == NULL)return;
        dfs(root->left,prev,ans);
        if(prev != INT_MIN)ans = min(ans , root->val - prev);
        prev = root->val;
        dfs(root->right , prev , ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX , prev = INT_MIN;
        if(root == NULL)return 0;
        dfs(root,prev,ans);
        return ans;
    }
};