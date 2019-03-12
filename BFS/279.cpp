class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;i + j*j <= n;j++) 
                dp[i+j*j] = min(dp[i]+1,dp[i+j*j]);
        }
        return dp[n];
    }
};