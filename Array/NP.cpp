#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 0)
            return;
        int index = n-1;
        while(index > 0){
            if(nums[index-1] < nums[index])
                break;
            index--;
        }
        if(index > 0){
            index--;
            int greater = n-1;
            while(greater >= 0 && nums[greater] <= nums[index])
                greater--;
            swap(nums[greater],nums[index]);
            index++;
        }
        n--;
        while(index < n){
            swap(nums[index],nums[n]);
            n--;
            index++;
        }
    }

};

int main(){
    vector<int> tmp;
    tmp.push_back(1),tmp.push_back(3),tmp.push_back(2);
    Solution s = Solution();
    s.nextPermutation(tmp);
    for(int i = 0;i < tmp.size();i++)
        cout<<tmp[i]<<endl;
}