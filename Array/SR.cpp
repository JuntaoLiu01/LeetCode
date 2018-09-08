#include <vector>
#include <string> 

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n < 1)
            return res;
        int pre = 0,start = 0;
        while(start < n){
            while(start == 0 || (start < n && nums[start] - nums[start-1] == 1))
                start++;
            if(start - 1 == pre)
                res.push_back(to_string(nums[pre]));
            else
                res.push_back(to_string(nums[pre]) + "->" + to_string(nums[start-1]));
            pre = start;
            start++;
        }
        if(pre == n-1)
            res.push_back(to_string(nums[pre]));
        return res;
    }
};