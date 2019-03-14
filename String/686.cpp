#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string tmp = A;
        int res = 1;
        while(tmp.size() < B.size()){
            tmp += A;
            res++;
        }
        if(tmp.find(B) != string::npos)
            return res;
        tmp += A;
        if(tmp.find(B) != string::npos)
            return res+1;
        return -1;
    }
};