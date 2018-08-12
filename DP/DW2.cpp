#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        const int Mod = 1000000007;
        vector<long long> dp(size,0);
        if('1' <= s[0] && s[0] <= '9')
            dp[0] = 1;
        else if(s[0] == '*')
            dp[0] = 9;
        if(s[0] != '*' && s[1] != '*'){
            int num = stoi(s.substr(0,2));
            if((11<= num  && num <= 19) || (21<= num && num <=26))
                dp[1] = 2;
            if(27<= num && num%10)
                dp[1] = 1;
            if(num == 10 || num == 20)
                dp[1] = 1;
        }
        else{
            if(s[0] == '*'){
                if(s[1] == '*')
                    dp[1] = 81+15;
                else if(s[1] != '0')
                    dp[1] = 9+2;
                else dp[1] = 2;
            }
            else if(s[0] == '1')
                dp[1] = 9+9;
            else if(s[0] == '2')
                dp[1] = 9+6;
            else if(s[0] != '0')
                dp[1] = 9;
        }   

        for(int i = 2;i < size;i++){
            if(s[i] != '*'){
                if(s[i] != '0')
                    dp[i] += dp[i-1];    
                if(s[i-1] == '1' || (s[i-1] == '2' && ('0' <= s[i] && s[i] <= '6')))
                    dp[i] += dp[i-2];
                else if(s[i-1] == '*'){
                    dp[i] += dp[i-2];
                    if('0' <= s[i] && s[i] <= '6')
                        dp[i] += dp[i-2];
                }
            }
            else{
                dp[i] += 9*dp[i-1];
                if(s[i-1] == '1')
                    dp[i] += 9*dp[i-2];
                else if(s[i-1] == '2')
                    dp[i] += 6*dp[i-2];
                else if(s[i-1] == '*')
                    dp[i] += 15*dp[i-2];
            }
            dp[i] %= Mod;
        }
        return dp[size-1]%Mod;
    }
};

int main(){
    string test="********************";
    Solution s = Solution();
    int ans = s.numDecodings(test);
    cout<<ans<<endl;
    return 0;
}