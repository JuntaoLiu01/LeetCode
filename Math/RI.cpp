#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> symbol({{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}});
        int res = 0;
        for(int i = 0;i < s.size();i++){
            res += symbol[s[i]];
            if(i > 0 && symbol[s[i]] > symbol[s[i-1]])
                res -= 2*symbol[[i-1]];
        }
        return res;
    }
};