class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res  = 0;
        int n = A.size();
        int l = A[0].size();
        for(int i = 0;i < l;i++){
            bool f = true;
            for(int j = 0;j < n-1 && f;j++){
                if(A[j][i] > A[j+1][i]){
                    res++;
                    f = false;
                }      
            }
        }
        return res;
    }
};