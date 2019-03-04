class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        if(m==1 && n==1)
            if(obstacleGrid[0][0]==0)
                return 1;
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i = 1;i < m;i++){
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0] = 1;
        }
        for(int j = 1;j < n;j++){
            if(obstacleGrid[0][j]==1)
                break;
            dp[0][j] = 1;
        }
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++){
                if(obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};