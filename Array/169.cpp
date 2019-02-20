class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=-1,t=0;
        for(int i = 0;i < nums.size();i++){
            if(!t){
                res = nums[i];
                t = 1;
            }
            else{
                if(res == nums[i])
                    t++;
                else
                    t--;
            }
        }
        return res;
    }
};