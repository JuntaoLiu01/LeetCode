#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1,right = nums.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            int cnt = 0;
            for(auto a:nums){
                if(a <= mid)
                    cnt++;
            }
            if(cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};