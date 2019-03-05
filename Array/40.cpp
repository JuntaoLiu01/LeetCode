class Solution {
public:
    void cs(vector<int>& tmp,vector<vector<int>>& res,vector<int> candidates,int a,int target){
        if(target < 0)
            return;
        if(target == 0)
            res.push_back(tmp);
        for(int i = a;i < candidates.size();i++){
            if(i > a && candidates[i]==candidates[i-1])
                continue;
            tmp.push_back(candidates[i]);
            cs(tmp,res,candidates,a+1,target-candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        cs(tmp,res,candidates,0,target);
        return res;
    }
};