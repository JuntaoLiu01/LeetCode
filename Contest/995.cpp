class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0;
        int n = A.size();
        for(int i = 0;i <= n-K;i++){
            if(A[i]==1)
                continue;
            res++;
            for(int j = 0;j < K;i++)
                A[i+j] ^= 1;
        }
        for(int i = 0;i < n;i++)
            if(A[i]==0)
                return -1;
        return res;
    }
};