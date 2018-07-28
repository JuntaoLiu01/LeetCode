#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int findPivot(vector<int> nums){
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(mid == 0 || mid == nums.size()-1 ||
                (nums[mid-1] > nums[mid] && nums[mid+1] >= nums[mid]))
                return mid;
            if(nums[mid] >= nums[mid-1] && nums[mid] < nums[mid+1])
                return mid + 1;
                right = mid-1;
        }
        return 0;
    }
    int binarySearch(vector<int> nums,int l,int r,int target){
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return false;
        int pivot = findPivot(nums);
        cout<<pivot<<endl;
        if(nums[pivot] == target)
            return true;
        if(binarySearch(nums,0,pivot-1,target))
            return true;
        return binarySearch(nums,pivot+1,nums.size()-1,target);
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