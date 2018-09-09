#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int end = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(begin == nums.size())
            return {-1,-1};
        else
            return {begin,end};
    }
};

class Solution2 {
private:
    int lower(vector<int>& nums,int target){

    }
    int upper(vector<int>& nums,int target){

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower(nums,target);
        int end = upper(nums,target);
        if(begin == end)
            return {-1,-1};
        else
            return {begin,end};
    }
};