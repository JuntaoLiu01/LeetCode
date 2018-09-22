#include <vector>
#include <iostream>
#include <algorithm>
#define MAXNUM 1000

using namespace std;

struct SegTreeNode{
    int val;
    int addMark;
}segTree[MAXNUM];

void build(int root,vector<int>& nodes,int l,int r){
    segTree[root].addMark = 0;
    if(l==r)
        segTree[root].val = nodes[l];
    else{
        int mid = (l+r)/2;
        build(2*root+1,nodes,l,mid);
        build(2*root+2,nodes,mid+1,r);
        segTree[root].val = min(segTree[2*1+1].val,segTree[2*root+2].val);
    }
}

void pushDown(int root){
    if(segTree[root].addMark != 0){
        segTree[root*2+1].addMark += segTree[root].addMark;
        segTree[root*2+2].addMark += segTree[root].addMark;  
        segTree[root*2+1].val += segTree[root].addMark;
        segTree[root*2+2].val += segTree[root].addMark;
    }
}

int query(int root,int nstart,int nend,int qstart,int qend){
    if(qstart > nend || qend < nstart)
        return INT_MAX;
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    pushDown(root);
    int mid = (nstart+nend)/2;
    return min(query(2*root+1,nstart,mid,qstart,qend),query(2*root+2,mid+1,nend,qstart,qend));
}

void update(int root,int nstart,int nend,int ustart,int uend,int addVal){
    if(ustart > nend || uend < nstart)
        return;
    if(ustart <= nstart && uend >= nend){
        segTree[root].addMark += addVal;
        segTree[root].val += addVal;
        return;
    }
    pushDown(root);
    int mid = (nstart+nend)/2;
    update(2*root+1,nstart,mid,ustart,uend,addVal);
    update(2*root+2,mid+1,nend,ustart,uend,addVal);
    segTree[root].val = min(segTree[2*1+1].val,segTree[2*root+2].val);
}