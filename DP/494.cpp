#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> dp;
        dp[0] = 1;
        for(auto num:nums){
            unordered_map<int,int> t;
            for(auto a:dp){
                int sum = a.first,cnt = a.second;
                t[sum-num] += cnt;
                t[sum+num] += cnt;
            }
            dp = t;
        }
        return dp[S];
    }
};