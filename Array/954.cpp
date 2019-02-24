class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int N = 100000;
        vector<int> p(N+1);
        vector<int> n(N+1);
        for(int i = 0;i < A.size();i++){
            if(A[i] > 0)
                p[A[i]]++;
            else
                n[-A[i]]++;
        }
        for(int i = 0;i <= N/2;i++){
            if(p[i] && (p[2*i] -= p[i])<0 )
                return false;
            if(n[i] && (n[2*i] -= n[i])<0)
                return false;
        }
        return true;
    }
};