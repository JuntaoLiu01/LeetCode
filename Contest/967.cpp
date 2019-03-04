class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if(N==1)
            res.push_back(0);
        for(int i = 1;i <= 9;i++)
            dfs(N-1,K,i,res);
        return res;
    }
    void dfs(int N,int K,int cur,vector<int>& res){
        if(N==0){
            res.push_back(cur);
            return;
        }
        int l = cur % 10;
        if(l+K < 10)
            dfs(N-1,K,cur*10+l+K,res);
        if(l-K >= 0 && K != 0)
            dfs(N-1,K,cur*10+l-K,res);
    }
};