class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> dp(n,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> temp;
        for(int i = 0;i < n;i++){
            if(temp.size() == 0 || nums[i] > temp.back())
                temp.push_back(nums[i]);
            else {
                int l = 0, r = temp.size()-1;
                while(l < r){
                    int m = (l+r)/2;
                    if(temp[m] < nums[i])
                        l = m+1;
                    else
                        r = m;
                }
                temp[r] = nums[i];
            }
        }
        return temp.size();
    }
};