#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> _nums;
    void fsq(int start,set<vector<int> >& s,vector<int>& tmp,int len){
        if(tmp.size() == len)
            s.insert(tmp);
        for(int i = start;i < _nums.size();i++){
            if(tmp.empty() || _nums[i] >= tmp.back())
                tmp.push_back(_nums[i]);
            else
                continue;
            fsq(i+1,s,tmp,len);
            tmp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        _nums = nums;
        set<vector<int> > s;
        vector<int> tmp;
        for(int len = 2; len <= nums.size();len++)
            fsq(0,s,tmp,len);
        vector<vector<int> > res;
        for(auto t:s)
            res.push_back(t);
        return res;
    }
};