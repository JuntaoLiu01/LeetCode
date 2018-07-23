#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> ret(nums.size,false);
        int last = nums.size()-1;
        ret[last] = true;
        for(int i = nums.size()-2;i >= 0;i--){
            for(int j = min(last,i+nums[i]);j > i && !ret[i];j--){
                if(ret[j])
                    ret[i] = true;
            }
        }
        return ret[0];
    }
};