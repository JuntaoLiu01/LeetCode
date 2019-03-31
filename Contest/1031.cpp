class Solution {
public:
    int m,n;
    int xy[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int> >& A,vector<vector<int> >& visited,int x,int y){
        if(visited[x][y])
            return;
        visited[x][y] = 1;
        for(int i = 0;i < 4;i++){
            int curx = x+xy[i][0];
            int cury = y+xy[i][1];
            if(curx<0 || cury<0 || curx>=m || cury>=n || !A[curx][cury])
                continue;
            dfs(A,visited,curx,cury);
        }
    }
    int numEnclaves(vector<vector<int> >& A) {
        m = A.size();
        n = A[0].size();
        vector<vector<int> > visited(m,vector<int>(n,0));
        int res = 0;
        for(int i = 0;i < m;i++)
            if(A[i][0])
                dfs(A,visited,i,0);
        for(int i = 0;i < m;i++)
            if(A[i][n-1])
                dfs(A,visited,i,n-1);
        for(int j = 0;j < n;j++)
            if(A[0][j])
                dfs(A,visited,0,j);
        for(int j = 0;j < n;j++)
            if(A[m-1][j])
                dfs(A,visited,m-1,j);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(A[i][j] && !visited[i][j])
                    res++;
            }
        }
        return res;
    }
};