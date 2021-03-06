#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void getLeafs(TreeNode* root,vector<int>& leafs){
        if(root){
            getLeafs(root->left,leafs);
            if(!root->left && !root->right)
                leafs.push_back(root->val);
            getLeafs(root->right,leafs);
        } 
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;
        getLeafs(root1,leafs1);
        getLeafs(root2,leafs2);
        if(leafs1.size() == leafs2.size()){
            for(int i = 0; i < leafs1.size();i++)
                if(leafs1[i] != leafs2[i])
                    return false;
            return true;
        }
        return false;
    }
};