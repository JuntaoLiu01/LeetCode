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
    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_front(root);
        int res;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* t = q.back();
                res = t->val;
                q.pop_back();
                if(t->right)
                    q.push_front(t->right);
                if(t->left)
                    q.push_front(t->left);
            }
        }
        return res;
    }
};