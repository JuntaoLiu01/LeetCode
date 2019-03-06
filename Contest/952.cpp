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
        if(parent[p] != p){
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
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(),A.end());
        init(n+1);
        for(int a:A){
            int t = sqrt(a);
            for(int k = 2;k <= t;k++){
                if(a % k == 0){
                    join(a,k);
                    join(a,a/k);
                }
            }
        }
        int res = 1;
        unordered_map<int,int> m;
        for(int a:A){
            res = max(res,++m[find(a)]);
        }
        return res;
    }
};