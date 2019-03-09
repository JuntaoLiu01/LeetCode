/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l < 0 || r < 0)
            return -1;
        if(abs(l-r) > 1)
            return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) < 0?false:true;
    }
};