#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int ret = 0;
        int best = 0;
        int nextBest = 0;
        for(int i = 0;i < size-1;i++){
            nextBest = max(nextBest,i+nums[i]);
            if(best == i){
                best = nextBest;
                ret++;
            }
        }
        return ret;
    }
};