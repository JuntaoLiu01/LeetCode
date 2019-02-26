class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int> > q;
        int fresh=0;
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        int min = 0;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j]==2)
                    q.emplace(i,j);
            }
        while(!q.empty() && fresh){
            int sum = q.size();
            while(sum--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i = 0;i < 4;i++){
                    int curx=x+dx[i];
                    int cury=y+dy[i];
                    if(curx<0||cury<0||curx>=m||cury>=n||grid[curx][cury]!=1)
                        continue;
                    fresh--;
                    grid[curx][cury]=2;
                    q.emplace(curx,cury);
                }  
            }
            min++;
        }
        return fresh?-1:min;
    }
};