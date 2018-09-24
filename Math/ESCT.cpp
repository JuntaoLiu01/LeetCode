#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            res = char('A'+(n%26+25)%26)+res;
            n = n/26;
        }
        return res;
    }
};