class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> temp,start;
        int n = nums.size(),res=0,deg=0;
        for(int i = 0;i < n;i++){
            temp[nums[i]]++;
            if(temp[nums[i]] == 1)
                start[nums[i]] = i;
            if(temp[nums[i]] == deg)
                res = min(res,i-start[nums[i]]+1);
            else if(temp[nums[i]] > deg){
                deg = temp[nums[i]];
                res = i-start[nums[i]]+1;
            }
        }
        return res;
    }
};