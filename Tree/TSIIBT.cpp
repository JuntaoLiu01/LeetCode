#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


class Solution {
private:
    void genVector(TreeNode* root,vector<int>& tmp){
        if(root){
            genVector(root->left,tmp);
            tmp.push_back(root->val);
            genVector(root->right,tmp);
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> tmp;
        genVector(root,tmp);
        for(int i = 0;i < tmp.size();i++){
            if(tmp[i] + tmp[i] == k)
                continue;
            if(binary_search(tmp.begin(),tmp.end(),k-tmp[i]))
                return true;
        }
        return false;
    }
};

