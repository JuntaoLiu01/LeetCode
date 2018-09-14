struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
}

class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return NULL;
        root->right = convertBST(root->right);
        root->val += sum;
        sum = root->val;
        root->left = convertBST(root->left);
        return root;

    }
};