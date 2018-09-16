class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j])
                    area += grid[i][j] * 4 + 2;
                if(i > 0)
                    area -= min(grid[i][j],grid[i-1][j]) * 2;
                if(j > 0)
                    area -= min(grid[i][j],grid[i][j-1]) * 2;
            }
        }
        return area;
    }
};