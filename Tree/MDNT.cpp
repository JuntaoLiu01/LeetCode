#include <algorithm>
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
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        if(root->children.empty())
            return 1;
        int depth = 0;
        for(int i = 0;i < root->children.size();i++)
            depth = max(maxDepth(root->children[i]),depth);
        return depth+1;
    }
};