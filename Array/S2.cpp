#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:

    void backtracing(vector<int>& nums,vector<vector<int> >& res,vector<int>& tmp,int level){
        if(!tmp.empty())
            res.push_back(tmp);
        for(int i = level;i < nums.size();i++){
            tmp.push_back(nums[i]);
            backtracing(nums,res,tmp,i+1);
            tmp.pop_back();
            while(i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        backtracing(nums,res,tmp,0);
        tmp.clear();
        res.push_back(tmp);
        return res;
    } 
};

int main(){
    vector<int> tmp;
    tmp.push_back(1),tmp.push_back(2),tmp.push_back(2);
    Solution s = Solution();
    vector<vector<int> > res = s.subsetsWithDup(tmp);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
}