class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int l = A[0].size();
        vector<string> tmp(n,"");
        int res = 0;
        for(int j = 0;j < l;j++){
            vector<string> t = tmp;
            for(int i = 0;i < n;i++)
                t[i] += A[i][j];
            if(is_sorted(t.begin(),t.end()))
                tmp = t;
            else 
                res++;
        }
        return res;
    }
};