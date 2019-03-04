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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node){
                    while(!q.empty()){
                        TreeNode* t = q.front();
                        q.pop();
                        if(t)
                            return false;
                        i++;
                    }
                }
                else{
                    q.push(node->left);
                    q.push(node->right);
                }   
            }
        }
        return true;
    }
};