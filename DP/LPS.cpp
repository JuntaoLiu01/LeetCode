#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                if(i+k < n){
                    if(k == 0)
                        dp[i][i] = 1;
                    else{
                        if(s[i] == s[i+k])
                            dp[i][i+k] = 2+dp[i+1][i+k-1];
                        else 
                            dp[i][i+k] = max(dp[i+1][i+k],dp[i][i+k-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};