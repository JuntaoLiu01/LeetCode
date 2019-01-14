#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

void preOrder(Node* root){
    stack<Node*> s;
    Node* p = root;
    while(p || !s.empty()){
        if(p){
            cout<<p->val<<endl;
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top()->right;
            s.pop();
        }
    }
}

void inOrder(Node* root){
    stack<Node*> s;
    Node* p = root;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }
        else {
            cout<<s.top()->val<<endl;
            p = s.top()->right;
            s.pop();
        }
    }
}

void postOrder(Node* root){
    stack<Node*> s;
    Node* p = root;
    Node* pre = NULL;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            if(p->right && pre != p->right){
                p = p->right;
                s.push(p);
                p = p->left;
            }
            else{
                s.pop();
                cout<<p->val<<endl;
                pre = p;
                p = NULL;
            }
        }
    }
}

void postOrder2(Node* root){
    stack<Node*> s;
    Node* cur;
    Node* pre = NULL;
    s.push(root);
    while(!s.empty()){
        cur = s.top();
        if((!cur->left && !cur->right) || 
            (pre && (pre == cur->left || pre == cur->right))){
            cout<<cur->val<<endl;
            s.pop();
            pre = cur;
        }
        else{
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
    }
}

