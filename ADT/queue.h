#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class Type>
class Queue{
private:
    int f;
    int r;
    int MAXN;
    Type *q;
public:
    Queue(int n){
        MAXN = n;;
        q = new Type[MAXN];
        f = 0;
        r = 0;
    }
    ~Queue(){
        delete []q;
    }
    bool isEmpty(){
        return f == r;
    }
    int getSize(){
        return (r-f+MAXN)%MAXN;
    }
    void enqueue(Type x){
        try{
            if((r+1)%MAXN == f)
                throw runtime_error("Queue is full! Fail to load more elements!");
            q[r] = x;
            r = (r+1)%MAXN;  
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    //r point to invalid element
    Type dequeue(){
        try{
            if(f == r)
                throw runtime_error("Queue is empty! Fail to pop element!");
            Type data = q[f];
            f = (f+1)%MAXN;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }

    Type front(){
        try{
            if(f == r)
                throw runtime_error("Queue is empty! Fail to get f element!");
            return q[f];
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};

template <class Type> struct Node{
    Type data;
    Node * next;
    Node(int x):data(x),next(NULL){}
};
template <class Type>
class LQueue{
typedef Node<Type> NODE;
private:
    NODE *head,*tail;
    int n;
public:
    LQueue(){
        head = NULL;
        tail = NULL;
        n = 0;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int getSize(){
        return n;
    }
    void enqueue(Type x){
        NODE *p = new NODE(x);
        if(!head)
            head = p;
        else
            tail->next = p;
        tail = p;
        n++;
    }
    Type dequeue(){
        try{
            if(!head)
                throw runtime_error("LQueue is empty! Fail to get elements!");
            Type data = head->data;
            NODE* p = head->next;
            delete head;
            head = p;
            if(!p)
                tail = p;
            n--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type front(){
        try{
            if(!head)
                throw runtime_error("LQueue is empty! Fail to get elements!");
            return head->data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};

template <class Type>
struct DNode{
    Type data;
    DNode *prev;
    DNode *next;
    DNODE(Type x):data(x),prev(NULL),next(NULL);
};
template <class Type>
class DQueue{
typedef DNode<Type> DNODE;
private:
    DNODE *head;
    DNODE *tail;
    int n;
public:
    DQueue(){
        head = NULL;
        tail = NULL;
        n = 0;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int getSize(){
        return n;
    }
    void insertAtFirst(Type x){
        DNODE *p = new DNODE(x);
        if(!head){
            head = p;
            tail = head;
            n++;
            return;
        }
        head->prev = p;
        p->next = head;
        head = p;
        n++;
    }
    void insertAtLast(Type x){
        DNODE *p = new DNODE(x);
        if(!head){
            tail = p;
            head = tail;
            n++;
            return;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
        n++;
    }
    Type removeFirst(){
        try{
            if(head==NULL)
                throw runtime_error("Queue is Empty!");
            Type data = head->data;
            if(!head->next){
                delete head;
                head = NULL;
                tail = NULL;
            }
            else{
                DNODE *p = head->next;
                delete head;
                head = p;
                head->prev = NULL;
            }
            n--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type removeLast(){
        try{
            if(head==NULL)
                throw runtime_error("Queue is empty!");
            Type data = tail->data;
            if(!tail->prev){
                delete tail;
                tail = NULL;
                head = NULL;
            }
            else{
                DNODE *p = tail->prev;
                delete tail;
                tail = p;
                p->next = NULL;
            }
            n--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type first(){
        try{
            if(head==NULL)
                throw runtime_error("Queue is empty!");
            return head->data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type last(){
        try{
            if(head==NULL)
                throw runtime_error("Queue is empty!");
            return tail->data;
        }catch(runtim e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};
#endif