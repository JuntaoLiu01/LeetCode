class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> t;
        for(string word:wordDict)
            t.insert(word);
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < i;j++)
                if(dp[j] && t.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
        }
        return dp.back();
    }
};