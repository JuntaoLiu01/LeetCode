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