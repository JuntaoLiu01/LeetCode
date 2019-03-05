class Solution {
public:
    void cs(vector<int>& tmp,vector<vector<int>>& res,int a,int k,int target){
        if(target < 0)
            return;
        if(target == 0 && tmp.size() == k)
            res.push_back(tmp);
        for(int i = a;i <= 9;i++){
            tmp.push_back(i);
            cs(tmp,res,i+1,k,target-i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        cs(tmp,res,1,k,n);
        return res;
    }
};