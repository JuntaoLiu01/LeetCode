#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n,0);
        for(int i = 1;i < n;i++){
            dp[i] = i+1;
            for(int j = 1;j <= i;j++){
                if((i+1)%j == 0)
                    dp[i] = min(dp[i],dp[j-1]+(i+1)/j);
            }
        }
        return dp[n-1];
    }
};