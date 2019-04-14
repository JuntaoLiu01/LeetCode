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
int maxDiff = 0;
public:
    pair<int,int> dfs(TreeNode* root){
        pair<int,int> res;
        if(!root)
            return res;
        if(!root->left && !root->right)
            return make_pair(root->val,root->val);
        if(!root->left){
            pair<int,int> rres = dfs(root->right);
            maxDiff = max(maxDiff,max(abs(rres.first-root->val),abs(rres.second-root->val)));
            res.first = min(rres.first,root->val);
            res.second = max(rres.second,root->val);
            return res;
        }
        if(!root->right){
            pair<int,int> lres = dfs(root->left);
            maxDiff = max(maxDiff,max(abs(lres.first-root->val),abs(lres.second-root->val)));
            res.first = min(lres.first,root->val);
            res.second = max(lres.second,root->val);
            return res;
        }
        pair<int,int> lres = dfs(root->left);
        pair<int,int> rres = dfs(root->right);
        int maxl = max(abs(lres.first-root->val),abs(lres.second-root->val));
        int maxr = max(abs(rres.first-root->val),abs(rres.second-root->val));
        maxDiff = max(maxDiff,max(maxl,maxr));
        res.first = min(root->val,min(lres.first,rres.first));
        res.second = max(root->val,max(lres.second,rres.second));
        return res;
    }
    int maxAncestorDiff(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return maxDiff;
    }
};