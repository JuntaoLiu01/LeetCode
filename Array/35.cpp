class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        int res = 0;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                l = mid+1;
                res = l;
            }
                
            else{
                r = mid;  
                res = r;
            }
                
        }
        return res;
    }
};