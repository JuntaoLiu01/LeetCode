#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size,size);
        ret[size-1] = 0;
        for(int i = nums.size()-2;i >= 0;i--){
            for(int j = min(size-1,i+nums[i]);j > i && ret[j] != size;j--){
                ret[i] = min(ret[i],ret[j]+1);
            }
        }
        return ret[0];
    }
};