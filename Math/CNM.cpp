#include <string>
using namespace std;

class Solution {
public:
    vector<int> parseArgs(string str){
        int i=0;
        while(str[i]!='+')
            i++;
        int a = stoi(str.substr(0,i));
        int start=i+1;
        while(str[i]!='i')
            i++;
        int b = stoi(str.substr(start,i-start+1));
        return {a,b};
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> arg1 = parseArgs(a);
        int a1=arg1[0],b1=arg1[1];
        vector<int> arg2 = parseArgs(b);
        int a2=arg2[0],b2=arg2[1];
        int x = a1*a2-b1*b2;
        int y = a1*b2+a2*b1;
        return to_string(x)+"+"+to_string(y)+"i";
    }
};