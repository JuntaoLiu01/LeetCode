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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> cur;
            for(int i = 0;i < n;i++){
                TreeNode* t = q.front();
                q.pop();
                cur.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if((count++)%2)
                reverse(cur.begin(),cur.end());
            res.push_back(cur);
        }
        return res;
    }
};