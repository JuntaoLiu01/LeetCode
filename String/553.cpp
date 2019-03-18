class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = to_string(nums[0]);
        int n = nums.size();
        if(n==1)
            return res;
        if(n==2)
            return res + "/" + to_string(nums[1]);
        res += "/(" + to_string(nums[1]);
        for(int i = 2;i < n;i++)
            res += "/" + to_string(nums[i]);
        res += ")";
        return res;
    }
};