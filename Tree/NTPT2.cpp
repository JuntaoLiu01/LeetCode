//pretraversal
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
    void preTraversal(Node* root,vector<int>& nodes){
        if(root){
            nodes.push_back(root->val);
            for(int i = 0;i < root->children.size();i++)
                preTraversal(root->children[i],nodes);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preTraversal(root,res);
        return res;
    }
};