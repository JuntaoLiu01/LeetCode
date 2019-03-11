class Solution {
public:
    int m;
    int n;
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<int>>& A,queue<pair<int,int>>& q,int x,int y){
        if(A[x][y]==1){
            A[x][y] = 2;
            q.emplace(x,y);
            for(int i = 0;i < 4;i++){
                int nx = x+xy[i][0];
                int ny = y+xy[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                    dfs(A,q,nx,ny);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int,int>> q;
        m = A.size();
        n = A[0].size();
        bool f = true;
        for(int i = 0;i<n && f;i++)
            for(int j = 0;j<n && f;j++)
                if(A[i][j]){
                    dfs(A,q,i,j);
                    f = false;
                }
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0;i < 4;i++){
                    int nx = x+xy[i][0];
                    int ny = y+xy[i][1];
                    if(nx<0 || nx>=m || ny<0 || ny>=n || A[nx][ny]==2)
                        continue;
                    if(A[nx][ny]==1)
                        return res;
                    A[nx][ny] = 2;
                    q.emplace(nx,ny);
                }
            }
            res++;
        }
        return res;    
    }
};