class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int count = 0;
    void init(int n){
        count = n;
        for(int i = 0;i < n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int p){
        while(p != parent[p]){
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
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        init(m*n);
        int num = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j]=='1'){
                    grid[i][j] = '0';
                    num++;
                    for(int k = 0;k < 4;k++){
                        int x = i+xy[k][0];
                        int y = j+xy[k][1];
                        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1')
                            join(i*m+j,x*m+y);
                    }
                }
            }
        }
        return num-(m*n-count);
    }
};


class Solution {
private:
    int m;
    int n;
public:
    int numIslands(vector<vector<char> >& grid) {
        m = grid.size();
        if(m < 1)
            return 0;
        n = grid[0].size();
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid,i,j);
                }     
            }
        }
        return res;
    }

    void dfs(vector<vector<char> >& grid,int i,int j){
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            dfs(grid,i-1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
            dfs(grid,i+1,j);
        }
    }
};