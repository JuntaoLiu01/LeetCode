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
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root,NULL);
    }
    TreeNode* dfs(TreeNode* root,TreeNode* tail){
        if(!root)
            return NULL;
        TreeNode* newRoot = root;
        if(root->right)
            root->right = dfs(root->right,tail);
        else
            root->right = tail; 
        if(root->left){
            newRoot = dfs(root->left,root);
            root->left = NULL;
        }
        return newRoot;
    }
};