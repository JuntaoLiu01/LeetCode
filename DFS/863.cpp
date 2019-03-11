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
    int dfs(TreeNode* root,TreeNode* target,int K){
        if(!root)
            return -1;
        if(root==target){
            collect(root,K);
            return 0;
        }  
        int l = dfs(root->left,target,K);
        int r = dfs(root->right,target,K);
        if(l < 0 && r < 0)
            return -1;
        if(l >= 0){
            if(l==K-1)
                res.push_back(root->val);
            collect(root->right,K-l-2);
            return 1+l;
        }
        else{
            if(r==K-1)
                res.push_back(root->val);
            collect(root->left,K-r-2);
            return 1+r;
        }  
    }
    void collect(TreeNode* root,int K){
        if(!root || K < 0)
            return;
        if(K==0){
            res.push_back(root->val);
            return;
        }
        collect(root->left,K-1);
        collect(root->right,K-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root,target,K);
        return res;
    }
};