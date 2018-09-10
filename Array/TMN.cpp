#include <vector> 
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first=INT64_MIN,second=INT64_MIN,third=INT64_MIN;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] < first){
                if(nums[i] > second){
                    third = second;
                    second = nums[i];
                }
                else if(nums[i] < second){
                    if(nums[i] > third)
                        third = nums[i];
                }
            }
        }
        if(third == INT64_MIN)
            return first;
        else
            return third;
    }
};
