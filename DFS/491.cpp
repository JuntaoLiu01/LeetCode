class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> res;
        dfs(nums,t,res,0);
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& t,vector<vector<int>>& res,int x){
        set<int> s;
        for(int i = x;i < nums.size();i++){
            if(!t.empty() && nums[i] < t.back())
                continue;
            if(s.count(nums[i]))
                continue;
            s.insert(nums[i]);
            t.push_back(nums[i]);
            if(t.size() > 1)
                res.push_back(t);
            dfs(nums,t,res,i+1);
            t.pop_back();
        }
    }
};