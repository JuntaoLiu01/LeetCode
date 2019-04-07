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
    void dfs(TreeNode* root,int pre,int& res){
        if(!root)
            return;
        if(!root->left && !root->right){
            res += pre*2 + root->val;
            return;
        }
        dfs(root->left,pre*2+root->val,res);
        dfs(root->right,pre*2+root->val,res);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        int pre = 0;
        dfs(root,pre,res);
        return res;
    }
};