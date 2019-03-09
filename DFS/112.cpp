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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->left && !root->right){
            if(root->val == sum)
                return true;
            return false;
        }
        bool l = hasPathSum(root->left,sum-root->val);
        bool r = hasPathSum(root->right,sum-root->val);
        return (l||r)?true:false;
    }
};