#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string res,token;
        while(getline(str,token,' ')){
            int n=token.size();
            for(int i = 0;i < n/2;i++)
                swap(token[i],token[n-1-i]);
            res += token+" ";
        }
        res.pop_back();
        return res;
    }
};