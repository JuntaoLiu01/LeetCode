#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        if(tmp[n-1] >= 2*tmp[n-2])
            for(int i = 0;i < n;i++){
                if(nums[i] == tmp[n-1])
                    return i;
            }
        return -1;
    }
};