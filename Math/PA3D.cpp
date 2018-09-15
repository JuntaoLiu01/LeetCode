class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0, front  = 0, left = 0;
        for(int i = 0;i < grid.size();i++){
            int x = 0,y = 0;
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j])
                    top++;
                    x = max(x,grid[i][j]);
                    y = max(y,grid[j][i]);
            }
            front += x;
            left += y;
        }
        return front + left + top;
    }
};