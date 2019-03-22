class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size(), M = 1e9+7;
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int i = 0;i < n;i++)
            dp[i][i] = 1;
        for(int k = 1;k < n;k++){
            for(int i = 0;i < n-k;i++){
                int j = i + k;
                if(S[i]==S[j]){
                    int left = i+1,right = j-1;
                    while(left <= right && S[left] != S[i])
                        left++;
                    while(left <= right && S[right] != S[j])
                        right--;
                    if(left > right)
                        dp[i][j] = dp[i+1][j-1]*2 + 2;
                    else if(left == right)
                        dp[i][j] = dp[i+1][j-1]*2 + 1;
                    else
                        dp[i][j] = dp[i+1][j-1]*2-dp[left+1][right-1];
                }
                else
                    dp[i][j] = dp[i+1][j]+dp[i][j-1] - dp[i+1][j-1];
                dp[i][j] = dp[i][j]<0?M+dp[i][j]:dp[i][j]%M;
            }
        }
        return dp[0][n-1];
    }
};