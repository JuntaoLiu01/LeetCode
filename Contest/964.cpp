class Solution {
public:
    map<int,int> m;
    int leastOpsExpressTarget(int x, int target) {
        return dfs(x,target);
    }
    int dfs(int x,int t){
        if(t==0)
            return 0;
        if(t < x)
            return min(2*t-1,(x-t)*2);
        if(m.count(t))
            return m[t];
        int k = log(t)/log(x);
        long p = pow(x,k);
        if(p==t){
            m[t] = k-1;
            return k-1;
        }
        int res = dfs(x,t-p)+k;
        long left = p * x - t;
        if(left < t)
            res = min(res,dfs(x,left)+k+1);
        m[t] = res;
        return res;
    }
};