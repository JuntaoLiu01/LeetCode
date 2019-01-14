#include <iostream>

using namespace std;

class BST{
private:
    int val;
    BST* parent;
    BST* left;
    BST* right;

public:
    BST(int x):val(x),parent(NULL),left(NULL),right(NULL) {}

    BST* search(BST* root,int k){
        BST* t = root;
        while(!t && t->val != k){
            if(t->val < k)
                t = t->left;
            else
                t = t->right;
        }
        return t;
    }

    BST* min(BST* root){
        BST* t = root;
        // if(!p) return NULL;
        while(t->left)
            t = t->left;
        return t;
    }

    BST* max(BST* root){
        BST* t = root;
        // if(!p) return NULL;
        while(t->right)
            t = t->right;
        return t;
    }

    void inorder(BST* root){
        if(!root){
            inorder(root->left);
            cout<<root->val<<'\t';
            inorder(root->right);
        }
    }

    BST* successor(BST* node){
        if(node->right)
            return min(node->right);
        BST* p = node->parent;
        while(p && node == p->right){
            node = p;
            p = p->parent;
        }
        return p;
    }

    BST* predecesser(BST* node){
        if(node->left)
            return max(node->left);
        BST* p = node->parent;
        while(p && node == p->left){
            node = p;
            p = p->parent;
        }
        return p;
    }

    BST* insert(BST* root,BST* node){
        BST* p = NULL;
        BST* t = root;
        while(t){
            p = t;
            if(t->val > node->val)
                t = t->left;
            else
                t = t->right;
        }
        node->parent = p;
        if(!p)
            return node;
        if(node->val < p->val)
            p->left = node;
        else 
            p->right = node;
        return root;
    }

    BST* insert(BST* root,int k){
        BST* node = new BST(k);
        return insert(root,node);
    }

    BST* del(BST* root,BST* node){
        BST* p = NULL;
        if(!node->left || !node->right)
            p = node;
        else
            p = successor(node);

        BST* t = NULL;
        if(p->left)
            t = p->left;
        else
            t = p->right;

        if(t)
            t->parent = p->parent;

        if(!p->parent)
            return t;
        else if(p == p->parent->left){
            p->parent->left == t;
        }
        else p->parent->right = t;

        if(p != node)
            node->val = p->val;

        return root;
    }
};