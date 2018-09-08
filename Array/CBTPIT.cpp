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
    TreeNode* build(vector<int>& preorder,int preleft,int prelast, vector<int>& inorder,int inleft,int inlast){
        if(preleft == prelast)
            return NULL;
        int val = preorder[preleft];
        TreeNode* root = new TreeNode(val);
        int i = inleft;
        while(i < inlast){
            if(inorder[i] != val)
                i++;
            else
                break;
        }
        int len = i - inleft;
        root->left = build(preorder,preleft+1,preleft+1+len,inorder,inleft,i);
        root->right = build(preorder,preleft+1+len,prelast,inorder,i+1,inlast);
        return root;     
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};