#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        for(int i = 3;i <= n;i++){
            for(int j = 1;j <= i/2;j++)
                dp[i] = max(max(dp[j],j)*max(dp[i-j],i-j), dp[i]);
        }
        return dp[n];
    }
};