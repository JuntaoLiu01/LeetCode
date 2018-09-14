#include <string>

using namespace std;

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        string res = to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        if(left == "" && right == "")
            return res;
        if(left == "")
            return res+"()("+right+")";
        if(right == "")
            return res+"("+left+")";
        return res+"("+left+")("+right+")"; 
    }
};