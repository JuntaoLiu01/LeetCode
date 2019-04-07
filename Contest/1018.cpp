class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n,false);
        int cnt = 0;
        for(int i = 0;i < n;i++){
            cnt = (cnt*2+A[i])%5;
            if(!cnt)
                res[i] = true;
        }
        return res;
    }
};