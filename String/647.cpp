class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int res = 0;
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                if(i + k < n){
                    if(k==0)
                        dp[i][i] = 1;
                    else{
                        if(s[i]==s[i+k])
                            if(k < 2 && dp[i+1][i+k-1])
                                dp[i][i+k] = 1;   
                    }
                    if(dp[i][i+k])
                        res++;
                }  
            }
        }
        return res;
    }
};