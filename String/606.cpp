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
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        string res = to_string(t->val);
        if(l=="" && r=="")
            return res;
        if(l=="")
            return res+"()(" +r+")";
        if(r=="")
            return res+"("+l+")";
        return res+"("+l+")("+r+")";
    }
};