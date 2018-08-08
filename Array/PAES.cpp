# include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(),1);
        int pre = 1;
        for(int i = 0;i < nums.size();i++){
            ret[i] *= pre;
            pre *= nums[i];
        }
        int pos = 1;
        for(int i = nums.size()-1;i >= 0;i--){
            ret[i] *= pos;
            pos *= nums[i];
        }
        return ret;
    }
};