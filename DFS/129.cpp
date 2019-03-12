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
    vector<string> dfs(TreeNode* root){
        vector<string> res;
        if(!root)
            return res;
        vector<string> l = dfs(root->left);
        vector<string> r = dfs(root->right);
        if(l.empty() && r.empty())
            res.push_back(to_string(root->val));
        for(int i = 0;i < l.size();i++)
            res.push_back(to_string(root->val)+l[i]);
        for(int j = 0;j < r.size();j++)
            res.push_back(to_string(root->val)+r[j]);
        return res;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> t = dfs(root);
        int sum = 0;
        for(int i = 0;i < t.size();i++)
            sum += stoi(t[i]);
        return sum;
    }
};