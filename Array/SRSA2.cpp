#include <vector>
#include <iostream>

using namespace std;

class Solution {   
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 1)
            return false;
        int left = 0,right = n - 1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < nums[right]){
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] > nums[right]){
                if(nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                right--;
        }
        return false;
    }
};

int main(){
    int tmp[5] = {2,2,2,0,1};
    vector<int> test(5);
    for(int i = 0;i < 5;i++)
        test[i] = tmp[i];
    Solution s = Solution();
    int target = 0;
    bool ret = s.search(test,target);
    cout<<ret<<endl;

    return 0;
    
}