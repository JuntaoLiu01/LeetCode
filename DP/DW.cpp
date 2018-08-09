#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> dp(size,0);
        if('1' <= s[0] && s[0] <= '9')
            dp[0] = 1;
        int num = stoi(s.substr(0,2));
        if((11<= num  && num <= 19) || (21<= num && num <=26))
            dp[1] = 2;
        if(27<= num && num%10)
            dp[1] = 1;
        if(num == 10 || num == 20)
            dp[1] = 1;
        for(int i = 2;i < size;i++){
            if(s[i] != '0')
                dp[i] += dp[i-1];
            if(s[i-1] == '1' || (s[i-1] == '2' && ('0' <= s[i] && s[i] <= '6')))
                dp[i] += dp[i-2];
        }
        return dp[size-1];

    }
};

int main(){
    string test="0";
    Solution s = Solution();
    int ans = s.numDecodings(test);
    cout<<ans<<endl;
    return 0;
}