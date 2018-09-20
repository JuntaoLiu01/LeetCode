#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i+1;j < nums.size();j++){
                int sum  = nums[i] + nums[j];
                int left = j+1,right = nums.size(),target = j+1;
                while(left < right){
                    int mid = (left + right)/2;
                    if(nums[mid] >= sum){
                        right = mid;
                        target = right;
                    }  
                    else{
                        left = mid+1;
                        target = left;
                    }
                }
                res += target-j-1;
            }
        }
        return res;
    }
};