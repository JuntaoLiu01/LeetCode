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
    TreeNode* helper(vector<int>& preorder,int l,int r){
        if(l >= r)
            return NULL;
        TreeNode* root = new TreeNode(preorder[l]);
        int i = l;
        for(;i < r;i++){
            if(preorder[i] > preorder[l])
                break;
        }
        root->left = helper(preorder,l+1,i);
        root->right = helper(preorder,i,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size());
    }   
};