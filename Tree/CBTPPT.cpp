
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int> pre,vector<int> post,int l,int r,int p,int q){
    if(l == r)
        return NULL;
    TreeNode* root = new TreeNode(0);
    root->val = pre[l];
    int i = l+1;
    while(i < r){
        if(pre[i] == post[q-2])
            break;
        i++;
    }
    int len = i-l-1;
    root->left = buildTree(pre,post,l+1,i,p,p+len);
    root->right = buildTree(pre,post,i,r,p+len,q-1);
    return root;
}
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        TreeNode* root = buildTree(pre,post,0,n,0,n);
        return root;
    }
};