#include <iostream>
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

int main(){
    int m,n;
    cin>>m>>n;
    unionFind uf = unionFind(m);
    while(n--){
        int a,b;
        cin>>a>>b;
        uf.union_(a,b);
    }
    cout<<uf.getCount()<<endl;
    uf.union_(4,8);
    cout<<uf.getCount()<<endl;
    return 0;
}
