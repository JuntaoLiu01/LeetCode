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
    int father[101];
    int depth[101];
    void dfs(TreeNode* root,int d,int f){
        if(!root)
            return;
        depth[root->val] = d;
        father[root->val] = f;
        dfs(root->left,d+1,root->val);
        dfs(root->right,d+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,-1);
        return (depth[x]==depth[y] && father[x]!=father[y]);
    }
};