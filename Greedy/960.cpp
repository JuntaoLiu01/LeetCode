class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int l = A[0].size();
        vector<int> dp(l,1);
        for(int i = 0;i < l;i++){
            for(int j = 0;j < i;j++){
                bool f = true;
                for(int k=0;k < n && f;k++){
                    if(A[k][j] > A[k][i])
                        f = false;
                }
                if(f)
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return l-*max_element(dp.begin(),dp.end());
    }
};