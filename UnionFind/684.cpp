class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void init(int n){
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
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(1001);
        for(auto edge:edges){
            int a = find(edge[0]);
            int b = find(edge[1]);
            if(a == b)
                return edge;
            join(a,b);
        }
        return {};
    }
};