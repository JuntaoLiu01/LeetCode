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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int ll=(root->left?rob(root->left->left):0);
        int lr=(root->left?rob(root->left->right):0);
        int rl=(root->right?rob(root->right->left):0);
        int rr=(root->right?rob(root->right->right):0);
        return max(root->val+ll+lr+rl+rr,rob(root->left)+rob(root->right));
    }
    
};