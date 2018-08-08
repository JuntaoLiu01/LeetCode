#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1) 
            return nums[0];
        if(size == 2)
            return max(nums[0],nums[1]);
        int* dp = new int[size];
        dp[0] = nums[0],dp[1] = nums[1];
        for(int i = 2;i < size;i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        return dp[size-1];
    }
};