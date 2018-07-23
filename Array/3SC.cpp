#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(),nums.end());
        int closestSum = nums[0]+nums[1]+nums[2];
        for(int i = 0;i < nums.size()-2;i++){
            int second = i+1,third = nums.size()-1;
            while(second < third){
                int curSum = nums[i]+nums[second]+nums[third];
                if (curSum == target)
                    return curSum;
                if(abs(target - curSum) < abs(target - closestSum))
                    closestSum = curSum;
                if(curSum < target)
                    second++;
                else
                    third--;
            }
        }
        return closestSum;
    }
};