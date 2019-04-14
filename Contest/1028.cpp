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
    int n;
    TreeNode* parse(const string& s, int& i, int dep) {
        int num = 0;
        for(;i < n && s[i] != '-';i++)
            num = num * 10 + s[i]-'0';
        TreeNode* root = new TreeNode(num);
        int j = i,cnt = 0;
        for(;j < n && s[j]=='-';j++)
            cnt++;
        if(cnt == dep+1){
            i = j;
            root->left = parse(s,i,dep+1);
        }
        cnt = 0;
        for(j = i;j < n && s[j]=='-';j++)
            cnt++;
        if(cnt == dep+1){
            i = j;
            root->right = parse(s,i,dep+1);
        }
        return root;
    }
    TreeNode* recoverFromPreorder(string s) {
        n = s.size();
        int i = 0;
        TreeNode* root = parse(s, i, 0);
        return root;
    }
};