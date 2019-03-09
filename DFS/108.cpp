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
    TreeNode* convert(vector<int> nums,int l,int r){
        if(l < r){
            int mid = (l+r)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = convert(nums,l,mid);
            root->right = convert(nums,mid+1,r);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums,0,nums.size());
    }
};