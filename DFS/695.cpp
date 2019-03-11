class Solution {
public:
    int m;
    int n;
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int dfs(int a,int b,vector<vector<int>> grid,vector<vector<int>>& visited){
        if(visited[a][b] || !grid[a][b])
            return 0;
        visited[a][b] = 1;
        int sum = 1;
        for(int i = 0;i < 4;i++){
            int x = a+xy[i][0];
            int y = b+xy[i][1];
            if(x>=0 && x<m && y>=0 && y<n)
                sum += dfs(x,y,grid,visited);
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(visited[i][j] || !grid[i][j])
                    continue;
                res = max(res,dfs(i,j,grid,visited));
            }
        }
        return res;
    }
};