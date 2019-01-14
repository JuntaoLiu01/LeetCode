#ifndef AVL_H
#define AVL_H
#include <iostream>
using namespace std;

template <class Type> 
struct Node{
    int height;
    Type val;
    Node *parent;
    Node *left;
    Node *right;
    Node(int h,Type x):height(h),val(x),parent(NULL),left(NULL),right(NULL){}
};
template <class Type>
class AVL{
typedef Node<Type> NODE;
private:
    NODE *root;
public:
    AVL(){root = NULL;}
    AVL(Type x){
        root = new NODE(1,x);
    }
    AVL(NODE *node){
        root = node;
    }
    ~AVL(){
        destroy(root);
    }
    void destroy(NODE *p){
        destroy(p->left);
        destroy(p->right);
        deleteNode(p);
    }
    void deleteNode(NODE *p){
        if(p)
            delete p;
    }
    NODE* search(Type x){
        NODE *p = root;
        while(p && p->val != x){
            if(p->val < x)
                p = p->left;
            else 
                p = p->right;
        }
        return p;
    }
    NODE* min(){
        NODE *p = root; 
        while(p->left)
            p = p->left;
        return p;
    }
    NODE* max(){
        NODE* p = root;
        while(p->right)
            p = p->right;
        return p;
    }
    NODE* successor(NODE *node){
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
    NODE* predecessor(NODE *node){
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
    int height(NODE *node){
        if(!node)
            return 0;
        return node->height;

    }
    NODE* LLRotation(NODE *node){
        NODE *p = node->left;
        node->left = p->right;
        if(p->right)
            p->right->parent = node;
        p->right = node;
        node->parent = p;

        node->height = max(height(node->left),height(node->right))+1;
        p->height = max(height(p->left),node->height)+1;
        return p;
    }
    NODE* RRRotation(NODE *node){
        NODE *p = node->right;
        node->right = p->left;
        if(p->left)
            p->left->parent = node;
        p->left = node;
        node->parent = p;

        node->height = max(height(node->left),height(node->right))+1;
        p->height = max(node->height,height(p->right))+1;
        return p;
    }
    NODE* LRRotation(NODE *node){
        node->left = RRRotation(node->left);
        return LLRotation(node);
    }
    NODE* RLRotation(NODE *node){
        node->right = LLRotation(node->right);
        return RRRotation(node);
    }

    NODE* insert(NODE* tree,NODE *node){
        if(tree == NULL){
            tree = node;
            tree->heght = 1;
            return tree;
        }
        if(tree->val > node->val){
            NODE* p = insert(tree->left,node);
            tree->left = p;
            p->parent = tree;
            if(height(tree->left) - height(tree->right) == 2){
                if(tree->left->val > node->val)
                    LLRotation(tree);
                else
                    LRRotation(tree);
            }
        }
        else{
            NODE *p = insert(tree->right,node);
            tree->right = p;
            p->parent = tree;
            if(height(tree->right) - height(tree->left) == 2){
                if(tree->right->val > node->val)
                    RLRotation(tree);
                else
                    RRRotation(tree);
            }
        }
        tree->height = max(height(tree->left),height(tree->right)) + 1;
        return tree;
    }
    void insert(NODE *node){
        root = insert(root,node);
    }
    void insert(Type x){
        NODE *node = new NODE(1,x);
        insert(node);
    }

    NODE* remove(NODE* tree,NODE *node){
        if(tree == NULL)
            return NULL;
        if(node->val < tree->val){
            NODE *p = remove(tree->left,node);
            tree->left = p;
            if(!p)
                p->parent = tree;
            if(height(tree->right) - height(tree->left) == 2){
                NODE *t = tree->right;
                if(height(t->left) > height(t->right))
                    tree = RLRotation(tree);
                else
                    tree = RRRotation(tree);
            }
        }
        else if(node->val > tree->val){
            NODE *p = remove(tree->right,node);
            tree->right = p;
            if(p)
                p->parent = tree;
            if(height(tree->left) - height(tree->right) == 2){
                NODE *t = tree->left;
                if(height(t->left) > height(t->right))
                    tree = LLRotation(tree);
                else
                    tree = LRRotation(tree);
            }
        }
        else{
            if(!tree->left && !tree->right){
                if(height(tree->left) > height(tree->right)){
                    NODE *t = tree->left;
                    while(t->right)
                        t = t->right;
                    tree->val = t->val;
                    NODE *p = remove(tree->left,t);
                    tree->left = p;
                    if(p)
                        p->parent = tree;
                }
                else{
                    NODE *t = tree->right;
                    while(t->left)
                        t = t->left;
                    tree->val = t->val;
                    NODE *p = remove(tree->right,t);
                    tree->right = p;
                    if(p)
                        p->parent = tree;
                }
            }
            else{
                NODE *t = tree;
                tree = tree->left==NULL?tree->right:tree->left;
                delete t;
            }
        }
        return tree;
    }

    void remove(NODE *node){
        root = remove(root,node);
    }
};
#endif