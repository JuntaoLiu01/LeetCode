class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2)
            return false;
        int n = nums.size();
        int minf = INT_MIN;
        vector<int> dp(sum/2+1,INT_MIN);
        dp[0] = 0;
        for(int i = 0;i < n;i++){
            for(int v = sum/2;v >= nums[i];v--)
                dp[v] = max(dp[v],dp[v-nums[i]]);
        }
        return dp[sum/2]!=INT_MIN;
    }
};