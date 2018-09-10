#include <vector>
#include <unordered_map>

using namespace std;

// brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int sum = nums[i];
            if (sum == k) ++res;
            for (int j = i + 1; j < n; ++j) {
                sum += nums[j];
                if (sum == k) ++res;
            }
        }
        return res;
    }
};

// use hash table
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0,sum = 0;
        unordered_map<int,int> m = {{0,1}};
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            res += m[sum-k];
            m[sum]++;
        }
        return res;

    }
};
