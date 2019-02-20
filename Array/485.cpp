class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0,i = 0;
        while(i < n){
            if(nums[i] == 1){
                int j = i+1;
                while(j < n && nums[j] == 1)
                    j++;
                res = max(j-i,res);
                i = j;
            }
            i++;
        }
        return res;
    }
};