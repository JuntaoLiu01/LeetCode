#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        for(int i = 0;i < n-1;i++){
            if(nums[i] > nums[i+1]){
                if(flag){
                    flag = false;
                    if(i == 0 || nums[i+1] >= nums[i-1])
                        nums[i] = nums[i+1];
                    else
                        nums[i+1] = nums[i];
                } 
                else
                    return false;
            }
        }
        return true;
    }
};