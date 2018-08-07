#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 2)
            return nums;
        int n1 = nums[0],c1 = 1,n2 = 0,c2 = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == n1)
                c1++;
            else if(nums[i] == n2)
                c2++;
            else if(c1 && c2){
                c1--;
                c2--;
            }
            else{
                if(!c1){
                    n1 = nums[i];
                    c1++;
                }
                else{
                    n2 = nums[i];
                    c2++;
                }
            }
        }
        c1 = 0,c2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == n1) 
                c1++;
            else if(nums[i] == n2)
                c2++;
        }
        vector<int> ret;
        if(c1 > nums.size()/3)
            ret.push_back(n1);
        if(c2 > nums.size()/3)
            ret.push_back(n2);
        return ret;
    }
};