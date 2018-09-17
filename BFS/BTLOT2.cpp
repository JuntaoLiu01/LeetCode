#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> res,tmp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            for(int i = 0;i < n;i++){
                TreeNode* node = q.front();q.pop();
                t.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            tmp.push_back(t);
        }
        for(int i = tmp.size()-1;i >= 0;i--)
            res.push_back(tmp[i]);
        return res;
    }
};