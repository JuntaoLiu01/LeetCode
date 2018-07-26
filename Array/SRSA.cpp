#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int findPivot(vector<int>& nums){
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) /  2;
            if(mid == 0 || mid == nums.size() - 1 ||
                (nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]))
                return mid;
            else if(nums[mid] > nums[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums,int l,int r,int target){
        while(l <= r){
            int m = (l + r) /  2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        cout<<pivot<<endl;
        if(pivot < 0 || nums[pivot] == target)
            return pivot;
        
        int ret = binarySearch(nums,0,pivot-1,target);
        if(ret != -1)
            return ret;
        else 
            return binarySearch(nums,pivot+1,nums.size()-1,target);
    }
};

int main(){
    int tmp[2] = {3,1};
    vector<int> test(2);
    for(int i = 0;i < 2;i++)
        test[i] = tmp[i];
    Solution s = Solution();
    int target = 1;
    int ret = s.search(test,target);
    cout<<ret<<endl;

    return 0;
    
}