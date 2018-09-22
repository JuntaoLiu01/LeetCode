#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class NumArray {
public:
    vector<int> segTree;
    vector<int> nodes;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        if(n >= 1)
        {
            nodes = nums;
            segTree = vector<int>(2*n,0);
            build(0,nums,0,n-1);
        }      
    }
    void build(int root,vector<int>& nums,int l,int r){
        if(l==r){
            segTree[root] = nums[l];
            return;
        }  
        int mid = (l+r)/2;
        build(2*root+1,nums,l,mid);
        build(2*root+2,nums,mid+1,r);
        segTree[root] = segTree[2*root+1] + segTree[2*root+2];
    }
    void _update(int root,int nstart,int nend,int index,int val){
        if(nstart==nend){
            if(nstart == index){
                segTree[root] += -nodes[index]+val;
                nodes[index] = val;
            }   
            return;
        }
        int mid = (nstart+nend)/2;
        if(index <= mid)
            _update(2*root+1,nstart,mid,index,val);
        else
            _update(2*root+2,mid+1,nend,index,val);
        segTree[root] = segTree[2*root+1]+segTree[2*root+2];
    }
    void update(int i, int val) {
        _update(0,0,n-1,i,val);
    }
    void range(int root,int nstart,int nend,int qstart,int qend,int& res){
        if(qstart > nend || qend < nstart)
            return;
        if(qstart <= nstart && qend >= nend){
            res += segTree[root];
            return;
        }
        int mid = (nstart+nend)/2;
        range(2*root+1,nstart,mid,qstart,qend,res);
        range(2*root+2,mid+1,nend,qstart,qend,res);    
    }
    int sumRange(int i, int j) {
        int res = 0;
        range(0,0,n-1,i,j,res);
        return res;
    }
};

int main(){
    int t[10] = {-28,-39,53,65,11,-56,-65,-39,-43,97};
    vector<int> test(t,t+10);
    NumArray na = NumArray(test);
    int ch;
    while(cin>>ch){
        if(ch == 1){
            int l,r;
            cin>>l>>r;
            cout<<na.sumRange(l,r)<<endl;
        }
        else{
            int i,val;
            cin>>i>>val;
            na.update(i,val);
            cout<<na.nodes[i]<<endl;
        }
    }
    return 0; 
}