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
        int left = 0,right = nums.size();
        int pos = 0;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid + 1;
                pos = left;
            }
            else{
                right = mid;
                pos = right;
            }
        }
        return pos;
    }
    int upper(vector<int>& nums,int target){
        int left = 0, right = nums.size();
        int pos = 0;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] > target){
                right = mid;
                pos = right;
            }
            else{
                left = mid + 1;
                pos = left;
            }
        }
        return pos;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower(nums,target);
        int end = upper(nums,target);
        if(begin == end)
            return {-1,-1}; 
        else
            return {begin,end-1};
    }
};