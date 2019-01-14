#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <stdexcept>
#include <iostream>
using namespace std;

template <class Type>
class Vector{
private:
    int N;
    int n;
    Type *A;
public:
    Vector(int size){
        N = size;
        A = new Type[N];
        n = 0;
    }
    ~Vector(){
        delete []A;
    }
    bool isEmpty(){
        return n==0;
    }
    int getSize(){
        return n;
    }
    Type getAtRank(int r){
        try{
            if(r < 0 || r >= n)
                throw runtime_error("Index out border!");
            return A[r];
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type replaceAtRank(int r,Type x){
        try{
            if(r < 0 || r >= n)
                throw runtime_error("Index out border!");
            Type data = A[r];
            A[r] = x;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type insertAtRank(int r,Type x){
        try{
            if(r < 0 || r >= n)
                throw runtime_error("Index out of border!");
            // expand the size of array
            if(n >= N){
                N = N*2;
                Type *B = new Type[N];
                for(int i = 0;i < n;i++)
                    B[i] = A[i];
                A = B;
            }
            for(int i = n;i > r;i++)
                A[i] = A[i-1];
            A[r] = x;
            n++;
            return x;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type removeAtRank(int r){
        try{
            if(r < 0 || r >= n)
                throw runtime_error("Index out of border!");
            Type data = A[r];
            for(int i = r;i < n;i++)
                A[i] = A[i+1];
            n--;
            return data;
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
    Node *prev;
    Node(Type x):data(x),next(NULL),prev(NULL){}
};

template <class Type>
class List{
typedef Node<Type> NODE;
private:
    int n;
    NODE *head;
    NODE *tail;
public:
    List(){
        n = 0;
        head = NULL;
        tail = NULL;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int getSize(){
        return n;
    }
    NODE* first(){
        try{
            if(!head)
                throw runtime_error("List is empty!");
            return head;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    NODE* last(){
        try{
            if(!head)
                throw runtime_error("List is empty!");
            return tail;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    NODE* getPrev(NODE *p){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            return p->prev;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    NODE* getNext(NODE *p){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            return p->next;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1); 
        }
    }
    Type replace(NODE* p,Type x){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            Type data = p->data;
            p->data = x;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    NODE* insertFirst(Type x){
        NODE* p = new NODE(x);
        if(head == NULL){
            head = p;
            tail = head;
        }
        else{
            p->next = head;
            head->prev = p;
            head  = p;
        }
        n++;
        return head;
    }
    NODE* insertLast(Type x){
        NODE* p = new NODE(x);
        if(head == NULL){
            tail = p;
            head = tail;
        }
        else{
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
        n++;
        return tail;
    }
    NODE* insertBefore(NODE* p,Type x){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            NODE* t = new NODE(x);
            if(p == head){
                t->next = head;
                head->prev = t;
                head = t;
            }
            else{
                NODE* q = p->prev;
                q->next = t;
                t->prev = q;
                t->next = p;
                p->prev = t;
            }
            n++;
            return t;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    NODE* insertAfter(NODE* p,Type x){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            NODE* t = new NODE(x);
            if(p == tail){
                tail->next = t;
                t->prev = tail;
                tail = t;
            }
            else{
                NODE* q = p->next;
                q->prev = t;
                t->next = q;
                t->prev = p;
                p->next = t;
            }
            n++;
            return t;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type remove(NODE* p){
        try{
            if(!p)
                throw runtime_error("param is null pointer!");
            Type data = p->data;
            if(p == head){
                NODE* q = head->next;
                if(head == tail){
                    delete head;
                    head == q;
                    tail = head;
                }
                else{
                    delete head;
                    q->prev = NULL;
                    head = q;
                }
            }
            else if(p == tail){
                NODE* q = tail->prev;
                delete tail;
                q->next = NULL;
                tail = q;
            }
            else{
                NODE* q = p->next;
                NODE* t = p->prev;
                delete p;
                t->next = q;
                q->prev = t;
            }
            n--;
            return data;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};

template <class Type,class T>
class Sequence:public List<Type>{
typedef Node<T> NODE;
public:
    NODE* rank2Pos(int r){
        try{
            if(r < 0 || r >= List::getSize())
                throw runtime_error("rank out of border!");  
            NODE* res;        
            if(r <= List::getSize()/2){
                NODE *p = List::first();
                while(r-- && p)
                    p = p->next;
                res = p;
            }
            else{
                NODE* p = List::last();
                r = List::getSize()-r;
                r--;
                while(r-- && p)
                    p = p->prev;
                res = p;
            }
            return res;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    int pos2Rank(NODE *p){
        try{
            if(!p)
                throw runtime_error("param is null poiner!");
            int r = 0;
            NODE* q = List::head;
            while(q && q!=p){
                q = q->next;
                r++;
            }
            return r;
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type getAtRank(int r){
        try{
            if(r < 0 || r >= List::getSize())
                throw runtime_error("Rank out of border!");
            return rank2Pos(r)->data;
            
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type replaceAtRank(int r,Type x){
        try{
            if(r < 0 || r >= getSize())
                throw runtime_error("Rank out of border!");
            return replace(rank2Pos(r),x);
            
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type insertAtRank(int r,Type x){
        try{
            if(r < 0 || r >= List::getSize())
                throw runtime_error("Rank out of border!");
            if(List::getSize() == r)
                return insertLast(x);
            else
                return insertBefore(rank2Pos(r),x);
            
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
    Type removeAtRank(int r){
        try{
            if(r < 0 || r >= List::getSize())
                throw runtime_error("Rank out of border!");
            return remove(rank2Pos(r));
            
        }catch(runtime_error e){
            cout<<e.what()<<endl;
            exit(-1);
        }
    }
};
#endif