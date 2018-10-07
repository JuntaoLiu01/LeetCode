#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = n/2;i >= 1;i--){
            if(n % i)
                continue;
            string cur = s.substr(0,i);
            bool flag = true;
            for(int j = i;flag && j < n;j += i){
                if(s.substr(j,i) != cur)
                    flag = false;
            }
            if(flag)
                return true;
        }
        return false;
    }
};