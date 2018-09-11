#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n < 1)
            return -1;
        vector<int> sums(n,0);
        for(int i = 0;i < n;i++)
            sums[i] += i==0?nums[i]:nums[i]+sums[i-1];
        for(int i = 0;i < n;i++){
            if(i == 0){
                if(sums[n-1]-sums[0] == 0)
                    return 0;
            }   
            else if(i == n-1){
                if(sums[n-2] == 0)
                    return n-1;
            }
                
            else if(sums[i-1] == sums[n-1]-sums[i])
                return i;
        }
        return -1;
    }
};