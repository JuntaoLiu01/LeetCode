class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = nums[0],maxSum = nums[0];
        for(int i = 1;i < n;i++){
            if(curSum < 0)
                curSum = 0;
            curSum += nums[i];
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};