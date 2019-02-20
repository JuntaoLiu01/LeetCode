class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> temp;
        for(int i = 0;i < nums.size();i++){
            temp[nums[i]]++;
            if(temp[nums[i]] >= 2)
                return true;
        }
        return false;
    }
};