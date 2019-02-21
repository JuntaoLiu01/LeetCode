class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],curSum=nums[0];
        for(int i = 1;i < nums.size();i++){
            if(curSum < 0)
                curSum = 0;
            curSum += nums[i];
            sum = max(sum,curSum);
        }
        return sum;
    }
};