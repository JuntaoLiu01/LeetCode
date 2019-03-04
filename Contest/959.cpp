class Solution {
public:
    int parent[3600];
    void init(int n){
        for(int i = 0;i < n;i++)
            parent[i] = i;
    }
    int find(int i){
        while(parent[i]!=i)
            i = parent[i];
        return i;
    }
    void join(int i,int j){
        int a = find(i);
        int b = find(j);
        if(a!=b)
            parent[a] = parent[b];
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = 4*n*n;
        init(m);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++){
                int t = 4*(i*n + j);
                if(i < n-1){
                    int t1 = 4*((i+1)*n + j);
                    join(t+2,t1);
                }
                if(j < n-1){
                    int t1 = 4*(i*n + j+1);
                    join(t+1,t1+3);
                }
            }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int t = 4*(i*n + j);
                if(grid[i][j] == '/'){
                    join(t,t+3);
                    join(t+1,t+2);
                }
                else if(grid[i][j] == '\\'){
                    join(t,t+1);
                    join(t+2,t+3);
                }
                else{
                    join(t,t+1);
                    join(t+1,t+2);
                    join(t+2,t+3);
                }
            }
        }
        int res = 0;
        for(int i = 0;i < m;i++)
            if(parent[i]==i)
                res++;
        return res;
    }
};