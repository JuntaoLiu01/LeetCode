class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int t1 = nums[0]*nums[1]*nums[n-1];
        int t2 = nums[n-3]*nums[n-2]*nums[n-1];
        return max(t1,t2);
    }
};