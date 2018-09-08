#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ret = nums[0];
        int left = 0,right = n-1;
        while(left <= right){
            int mid = (left+right)/2;           
            if(nums[mid] < nums[right]){
                if(nums[mid] < ret)
                    ret = nums[mid];
                right = mid-1;
            }
            else{
                if(nums[left] < ret)
                    ret = nums[left];
                left = mid+1;
            }
        }
        return ret;
    }
};
