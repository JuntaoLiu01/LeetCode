#include <vector>
using namespace std;

class unionFind{
private:
    int count;
    vector<int> size;
    vector<int> parent;
public:
    unionFind(int n){
        size = vector<int>(n);
        parent = vector<int>(n);
        count = n;
        for(int i = 0;i < n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int getCount(){
        return count;
    }
    bool validate(int p){
        int n = parent.size();
        if(p>=0 && p < n)
            return true;
        return false;
    }
    int find(int p){
        if(validate(p)){
            while(parent[p] != p){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        return -1;
    }

    bool connected(int p,int q){
        if(validate(p) && validate(q))
            return find(p) == find(q);
    }

    void union_(int p,int q){
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq)
            return;
        if(size[rootp] < size[rootq]){
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        }
        else{
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        }
        count--;
    }
};

class Solution {

public:
    int findCircleNum(vector<vector<int> >& M) {
        int n = M.size();
        unionFind uf = unionFind(n);
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(M[i][j])
                    uf.union_(i,j);
            }
        }
        return uf.getCount();
    }
};