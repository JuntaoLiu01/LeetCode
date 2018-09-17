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
private:

    TreeNode* traverse(TreeNode* root, TreeNode* tail) {
        if(!root)
            return NULL;
        TreeNode* newRoot = root;
        if(root->right)
            root->right = traverse(root->right,tail);
        else
            root->left = tail;
        if(root->left){
            newRoot = traverse(root->left,root);
            root->left = NULL;
        }
            
        return newRoot;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        return traverse(root, NULL);
    }
};