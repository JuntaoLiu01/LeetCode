#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
private:
    void postTraversal(Node* root,vector<int>& nodes){
        if(root){
            for(int i = 0;i < root->children.size();i++)
                postTraversal(root->children[i],nodes);
            nodes.push_back(root->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postTraversal(root,res);
        return res;
    }
};