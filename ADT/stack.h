#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include <iostream>

using namespace std;

template <class Type>
class Stack{
private:
    Type *stk;
    int pt;
    int MAXN;

public:
    Stack(int n){
        MAXN = n;
        pt = -1;
        stk = new Type[MAXN];
    }
    ~Stack(){
        delete [] stk;
    }
    int getSize(){
        return pt+1;
    }
    bool isEmpty(){
        return pt==-1;
    }
    void push(Type x){
        try{
            if(pt == MAXN-1)
                throw runtime_error("Stack is Full! Fail to load more elements!");  
            stk[++pt] = x;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
        
    }
    Type pop(){
        try{
            if(pt == -1)
                throw  runtime_error("Stack is empty! Fail to pop elements!");  
            int data = stk[pt]
            pt--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
        
    }
    Type top(){
        try{
            if(pt == -1)
                throw runtime_error("Stack is empty! Fail top get top element!");
            return stk[pt];
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }  
    }
};

template <class Type>
struct Node{
    Type data;
    Node *next;
    Node(Type x):data(x),next(NULL){}
};
template <class Type> 
class LStack{
typedef Node<Type> NODE;
private:
    int n;
    NODE *pt;
public: 
    LStack(){
        n = 0;
        pt = NULL;
    }

    int size(){
        return n;
    }
    bool empty(){
        return pt == NULL;
    }
    void push(Type x){
        NODE* p = new NODE(x);
        p->next = pt;
        pt = p;
        n++;
    }
    Type pop(){
        try{
            if(pt == NULL)
                throw runtime_error("LStack is empty! Fail to pop elements!");
            Type data = pt->data;
            NODE* p = pt->next;
            delete pt;
            pt = p;
            n--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type top(){
        try{
            if(pt == NULL)
                throw runtime_error("LStack is empty! Fail to get top element!");
            return pt->data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};
#endif