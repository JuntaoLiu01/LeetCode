class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int res = 1;
        int n = A.size();
        for(int i = 0;i < n-1;i++){
            for(int j = i+1;j < n;j++){
                int cnt = 2,diff = A[j]-A[i];
                int pre = A[j];
                for (int k = j+1;k < n;k++){
                    if(A[k]-pre == diff){
                        cnt++;
                        pre = A[k];
                    }
                }
                res = max(res,cnt);
            }
        }
        return res;
    }
};