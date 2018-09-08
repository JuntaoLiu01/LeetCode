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
    TreeNode* build(vector<int>& inorder,int inleft,int inright,vector<int>& postorder,int postleft,int postright){
        if(inleft == inright)
            return NULL;
        int val = postorder[postright];
        TreeNode* root = new TreeNode(val);
        int i = inleft;
        while(i < inright){
            if(inorder[i] != val)
                i++;
            else
                break;
        }
        int len = i - inleft;
        root->left = build(inorder,inleft,i,postorder,postleft,postleft+len);
        root->right = build(inorder,i+1,inright,postorder,postleft+len,postright-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size(),postorder,-1,postorder.size()-1);
    }
};