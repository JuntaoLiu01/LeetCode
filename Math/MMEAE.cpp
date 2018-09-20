#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int min_num = INT_MAX;
        for(int i = 0;i < n;i++)
            min_num = min(min_num,nums[i]);
        int res = 0;
        for(int i = 0;i <= n;i++)
            res += nums[i] - min_num;
        return res;
    }
};