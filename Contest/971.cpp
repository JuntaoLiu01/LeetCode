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
    vector<int> res;
    int index = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(dfs(root,voyage))
            return res;
        return {-1};
    }
    bool dfs(TreeNode* root,vector<int> voyage){
        if(!root)
            return true;
        if(root->val != voyage[index++])
            return false;
        if(root->left && root->left->val == voyage[index])
            return dfs(root->left,voyage) && dfs(root->right,voyage);
        if(root->right && root->right->val == voyage[index]){
            if(root->left)
                res.push_back(root->val);
            return dfs(root->right,voyage) && dfs(root->left,voyage);
        }
        return !root->left && !root->right;
    }
};