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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if(dfs(root,res)==0)
            res++;
        return res;
    }
    int dfs(TreeNode* root,int &res){
        if(!root)
            return 1;
        int l = dfs(root->left,res);
        int r = dfs(root->right,res);
        if(!l || !r){
            res++;
            return 2;
        }
        if(l == 2 || r == 2)
            return 1;
        return 0;
    }
};