class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int res=1;
        int i = 0;
        while(i < n){
            int j = i+1,key = nums[i];
            while(j < n && nums[j] > key){
                key = nums[j];
                j++;
            }
            res = max(res,j-i);
            i = j;
        }
        return res;
    }
};