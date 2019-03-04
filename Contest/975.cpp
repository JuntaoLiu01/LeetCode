class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<bool> high(n,false);
        vector<bool> low(n,false);
        high[n-1]=low[n-1]=true;
        map<int,int> m;
        m[A[n-1]] = n-1;
        int res = 0;
        for(int i = n-2;i >= 0;i--){
            auto h = m.lower_bound(A[i]);
            auto l = m.upper_bound(A[i]);
            if(h != m.end())
                high[i] = low[h->second];
            if(l != m.begin())
                low[i] = high[(--l)->second];
            if(high[i])
                res++;
            m[A[i]] = i;
        }
        return res;
    }
};