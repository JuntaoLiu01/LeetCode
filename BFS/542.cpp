class Solution {
public:
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                if(matrix[i][j] == 0){
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                }       
        }
        int step = 0;
        while(!q.empty()){
            int qn = q.size();
            for(int i = 0;i < qn;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                matrix[x][y] = step;
                for(int j = 0;j < 4;j++){
                    int curx = x+xy[j][0];
                    int cury = y+xy[j][1];
                    if(curx < 0 || cury < 0 || curx >= m || cury >= n || visited[curx][cury])
                        continue;
                    q.push(make_pair(curx,cury));
                    visited[curx][cury] = true;
                }
            }
            step++;
        }
        return matrix;
    }
};