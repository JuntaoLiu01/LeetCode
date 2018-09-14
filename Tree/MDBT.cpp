
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        depth = max(maxDepth(root->left),maxDepth(root->right));
        depth += 1;
        return depth; 
    }
};