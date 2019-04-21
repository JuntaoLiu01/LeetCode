class Solution {
public:
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int> > visited(R,vector<int>(C,0));
        vector<vector<int> > res;
        queue<pair<int,int> > q;
        q.push(make_pair(r0,c0));
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                auto node = q.front();
                q.pop();
                int x = node.first,y = node.second;
                if(!visited[x][y]){
                    visited[x][y] = 1;
                    res.push_back({x,y});
                    for(int j = 0;j < 4;j++){
                        int curx = x+xy[j][0];
                        int cury = y+xy[j][1];
                        if(curx < 0 || curx >= R || cury < 0 || cury >= C)
                            continue;
                        q.push(make_pair(curx,cury));
                    }
                }
            }
        }
        return res;   
    }
};