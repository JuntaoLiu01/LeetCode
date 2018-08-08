#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
       int size = nums.size();
       if(size == 0)
           return 0;
        if(size < 4){
            sort(nums.begin(),nums.end());
            return nums[size-1];
        }
        int* dp1 = new int[size];
        dp1[1] = nums[1],dp1[2] = nums[2];
        for(int i = 3;i < size;i++)
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);

        int* dp2 = new int[size];
        dp2[size-2] = nums[size-2],dp2[size-3] = nums[size-3];
        for(int j = size-4;j >= 0;j--)
            dp2[j] = max(dp2[j+1],dp2[j+2]+nums[j]);
        return max(dp1[size-1],dp2[0]);
    }
};