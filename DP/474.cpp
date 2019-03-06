class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string str:strs){
            int z = 0,o = 0;
            for(char ch:str){
                if(ch=='0')
                    z++;
                else 
                    o++;
            }
            for(int i = m;i >= z;i--)
                for(int j = n;j >= 0;j--)
                    dp[i][j] = max(dp[i][j],dp[i-z][j-o]+1);
        }
        return dp[m][n];
    }
};