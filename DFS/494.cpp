class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> dp;
        dp[0]=1;
        for(int num:nums){
            unordered_map<int,int> t;
            for(auto m:dp){
                int sum = m.first,cnt = m.second;
                t[sum+num] += cnt;
                t[sum-num] += cnt;
            }
            dp = t;
        }
        return dp[S];
    }
};