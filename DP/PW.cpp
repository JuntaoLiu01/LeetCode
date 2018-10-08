class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int k=0;k < n;k++){
            for(int i=0;i < n;i++){
                if(i+k < n){
                    if(k == 0)
                        dp[i][i] = nums[i];
                    else{
                        dp[i][i+k] = max(nums[i]-dp[i+1][i+k],nums[i+k]-dp[i][i+k-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};  