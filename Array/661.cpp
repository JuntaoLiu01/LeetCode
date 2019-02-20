class Solution {
public:
    int dp[9][3] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    bool isValid(int i,int j,int m,int n){
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(),n = M[0].size();
        vector<int>(m,vector<int>(n)) res;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int count=0,sum=0;
                for(int a=0;a<9;a++){
                    if(isValid(i+dp[a][0],j+dp[a][1],m,n)){
                        count++;
                        sum += M[i+dp[a][0]][j+dp[a][1]];
                    }
                }
                res[i][j] = sum/count;
            }
        }
        return res
    }
};