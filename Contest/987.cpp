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
    map<int,vector<pair<int,int>>> nodes;
    void dfs(int x,int y,TreeNode* root){
        if(!root)
            return;
        nodes[x].emplace_back(-y,root->val);
        dfs(x-1,y-1,root->left);
        dfs(x+1,y-1,root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(0,0,root);
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>>::iterator it;
        for(it = nodes.begin();it != nodes.end();it++){
            vector<int> tmp;
            sort(it->second.begin(),it->second.end());
            for (int i = 0;i < it->second.size();i++)
                tmp.push_back(it->second[i].second);
            res.push_back(tmp);
        }
        return res;
    }
};