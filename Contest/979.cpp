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
    int distributeCoins(TreeNode* root) {
        int res = 0;
        int t = balance(root,res);
        return res;
    }
    int balance(TreeNode* root,int &res){
        if(!root)
            return 0;
        int l = balance(root->left,res);
        int r = balance(root->right,res);
        res += abs(l) + abs(r);
        return root->val-1+l+r;
    }
};