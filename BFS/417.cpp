class Solution {
public:
    int m;
    int n;
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        m = matrix.size();
        if(m<1)
            return res;
        n = matrix[0].size();
        vector<vector<bool>> p(m,vector<bool>(n,false));
        vector<vector<bool>> a(m,vector<bool>(n,false));
        for(int i = 0;i < m;i++){
            dfs(matrix,p,INT_MIN,i,0);
            dfs(matrix,a,INT_MIN,i,n-1);
        }
        for(int j = 0;j < n;j++){
            dfs(matrix,p,INT_MIN,0,j);
            dfs(matrix,a,INT_MIN,m-1,j);
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(p[i][j] && a[i][j])
                    res.emplace_back(i,j);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& v,int pre,int x,int y){
        if(x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] < pre)
            return;
        if(v[x][y])
            return;
        v[x][y] = true;
        for(int i = 0;i < 4;i++)
            dfs(matrix,v,matrix[x][y],x+xy[i][0],y+xy[i][1]);
    }
};