#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-3;i++)
            for(int j = i+1;j < nums.size()-2;j++){
                int third = j+1,fourth = nums.size()-1;
                while(third < fourth){
                    int curSum = nums[i] + nums[j] + nums[third] + nums[fourth];
                    if(curSum  == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]),tmp.push_back(nums[j]);
                        tmp.push_back(nums[third]),tmp.push_back(nums[fourth]);
                        if(!s.count(tmp)){
                            result.push_back(tmp);
                            s.insert(tmp);
                        }
                        third++;
                    }
                    else if(curSum < target)
                        third++;
                    else
                        fourth--;
                }
                
            }
        return result;
    }
};