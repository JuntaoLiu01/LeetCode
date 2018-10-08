class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        vector<int> pick(n,0);
        vector<int> skip(n,0);
        sort(nums.begin(),nums.end());
        pick[0] = nums[0];
        skip[0] = 0;
        for(int i = 1;i < n;i++){
            if(nums[i-1] == nums[i]-1){
                skip[i] = max(skip[i-1],pick[i-1]);
                pick[i] = skip[i-1]+nums[i];
            }
            else if(nums[i-1] == nums[i]){
                pick[i] = pick[i-1]+nums[i];
                skip[i] = skip[i-1];
            }
            else{
                skip[i] = max(skip[i-1],pick[i-1]);
                pick[i] = max(skip[i-1],pick[i-1]) + nums[i];
            }
        }
        return max(pick[n-1],skip[n-1]);
    }
};