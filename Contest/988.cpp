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
    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return "";
        string left_str = smallestFromLeaf(root->left);
        string right_str = smallestFromLeaf(root->right);
        if(left_str == "")
            return right_str+char('a'+root->val);
        if(right_str == "")
            return left_str+char('a'+root->val);
        if(left_str.size() < right_str.size())
            return left_str+char('a'+root->val);
        if(left_str.size() > right_str.size())
            return right_str+char('a'+root->val);
        if(left_str <= right_str)
            return left_str+char('a'+root->val);
        return right_str+char('a'+root->val);
    }
};