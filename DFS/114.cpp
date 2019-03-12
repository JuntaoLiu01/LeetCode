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
    TreeNode* prev;
    void convert(TreeNode* root){
        if(!root)
            return NULL;
        dfs(root->left);
        prev->right = root;
        prev = root;
        prev->left = NULL;
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode* t = new TreeNode(0);
        prev = t;
        dfs(root);
        return t->right;
    }
};