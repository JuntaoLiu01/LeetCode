#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <class Type> 
struct Node{
    Type val;
    Node *parent;
    Node *left;
    Node *right;
    Node(Type x):val(x),parent(NULL),left(NULL),right(NULL){}
};
template <class Type>
class BST{
typedef Node<Type> NODE;
private:
    NODE *root;
public:
    BST(Type x){
        root = new NODE(x);
    }
    BST(NODE *p){
        root = p;
    }
    ~BST(){
        destroy(root);
    }
    void destroy(NODE* p){
        destroy(p->left);
        destroy(p->right);
        deleteNode(p);
    }
    void deleteNode(NODE *p){
        if(p)
            delete p;
    }
    NODE* search(Type x){
        NODE* t = root;
        while(t && t->val != x){
            if(t->val > x)
                t = t->left;
            else
                t = t->right;
        }
        return t;
    }
    NODE* min(){
        NODE* t = root;
        while(t->left)
            t = t->left;
        return t;
    }
    NODE* max(){
        NODE* t = root;
        while(t->right)
            t = t->right;
        return t;
    }
    void inorder(){
        midTranversal(root);
    }
    void midTranversal(NODE* p){
        if(!p){
            inorder(p->left);
            cout<<p->val<<endl; //visit p
            inorder(p->right);
        }
    }
    NODE* successor(NODE* node){
        if(node->right){
            NODE *t = node->right;
            while(t->left)
                t = t->left;
            return t;
        }
        NODE *p = node->parent;
        while(p && node == p->right){
            node = p;
            p = p->parent;
        }
        return p;
    }
    NODE* predecessor(NODE* node){
        if(node->left){
            NODE *t = node->left;
            while(t->right)
                t = t->right;
            return t;
        }
        NODE *p = node->parent;
        while(p && node == p->left){
            node = p;
            p = p->parent;
        }
        return p;
    }
    void insert(NODE *node){
        NODE *p = NULL;
        NODE *t = root;
        while(t){
            p = t;
            if(t->val < node->val)
                t = t->right;
            else
                t = t->left;
        }
        node->parent = p;
        if(!p)
            root = node;
        if(node->val > p->val)
            p->right = node;
        else
            p->left = node;
    }
    void insert(Type x){
        NODE *node = new NODE(x);
        insert(node);
    }
    void remove(NODE *node){
        NODE *p = NULL;
        if(!node->left || !node->left)
            p = node;
        else
            p = successor(node);
        NODE *t = NULL;
        if(p->left)
            t = p->left;
        else
            t = p->right;
        if(t)
            t->parent = p->parent;
        if(!p->parent)
            root = t;   
        else if(p == p->parent->left)
            p->parent->left = t;
        else
            p->parent->right = t;
        if(p != node)
            node->val = p->val;
    }
};

#endif