struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}

};

class Solution {
private:
    int postSum(TreeNode* root,int& res){
        if(!root)
            return 0;
        int leftSum = postSum(root->left,res);
        int rightSum = postSum(root->right,res);
        res += abs(leftSum-rightSum);
        return leftSum + rightSum + root->val;
    }
public:
    int findTilt(TreeNode* root) {  
        int res = 0;
        postSum(root,res);
        return res;    
    }
};