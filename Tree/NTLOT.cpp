#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        if(!root)
            return {};

        vector<vector<int> > res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int n = q.size();
            for(int i = 0;i < n;i++){
                Node* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for(int j = 0;j < t->children.size();j++)
                    q.push(t->children[j]);
            }
            res.push_back(tmp);
        }
        return res;    
    }
};