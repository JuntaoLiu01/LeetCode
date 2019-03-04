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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        if(root->left && root->right){
            if(root->val != root->left->val || root->val != root->right->val)
                return false;
            return isUnivalTree(root->left) && isUnivalTree(root->right);
        }
        if(root->left){
            if(root->val != root->left->val)
                return false;
            return isUnivalTree(root->left);
        }
        if(root->right){
            if(root->val != root->right->val)
                return false;
            return isUnivalTree(root->right);
        }
        return true;
    }
};