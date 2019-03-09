
class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int count;
    void init(int n){
        count = n;
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int p){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void join(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb)
            return;
        if(size[pa] < size[pb]){
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else{
            parent[pb] = pa;
            size[pa] += size[pb];
        }
        count--;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        init(n);
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(M[i][j])
                    join(i,j);
            }
        }
        return count;
    }
};