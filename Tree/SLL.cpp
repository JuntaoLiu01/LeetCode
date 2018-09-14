struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution {
private:
    int computeSum(TreeNode* root,bool isLeft){
        if(!root)
            return 0;
        if(!root->left && !root->right && isLeft)
            return root->val;
        int sum = 0;
        sum += computeSum(root->left,true);
        sum += computeSum(root->right,false);
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return computeSum(root,false);
    }
};