#include <vector>

using namespace std;

class Solution {
private:
    void cs(vector<int>& candidates,vector<vector<int> >& res,vector<int>& tmp,int level,int target){
        if(target < 0)
            return;
        if (target == 0)
            res.push_back(tmp);
        for(int i = level;i < candidates.size();i++){
            tmp.push_back(candidates[i]);
            cs(candidates,res,tmp,i,target-candidates[i]);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        cs(candidates,res,tmp,0,target);
        return res;
    }
};