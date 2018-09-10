#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(binary_search(nums.begin()+i+1,nums.end(),nums[i]+k))
                res++;
        }
        return res;
    }
};