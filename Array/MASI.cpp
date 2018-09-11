#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n,0);
        for(int i = 0;i < n;i++)
            sums[i] += i==0?nums[i]:nums[i]+sums[i-1];
        double res = sums[k-1];
        for(int i = k;i < n;i++)
            res = max(res,(double)sums[i]-sums[i-k]);
        return res/k;
    }
};