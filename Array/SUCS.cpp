#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        int start = -1,end = -1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != tmp[i]){
                if(start == -1)
                    start = i;
                else
                    end = i;
            }       
        }
        return end -start+1;
    }
};