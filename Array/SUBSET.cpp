#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ret;
        if(n == 1){
            ret.push_back(vector<int>());
            ret.push_back(nums);
            return ret;
        }
        int _num = nums[0];
        vector<int> newNums = nums;
        newNums.erase(newNums.begin());
        vector<vector<int> > tmp_ret = subsets(newNums);

        for(int i = 0;i < tmp_ret.size();i++){
            ret.push_back(tmp_ret[i]);
            tmp_ret[i].push_back(_num);
            ret.push_back(tmp_ret[i]);
        }
        return ret;
    }
};