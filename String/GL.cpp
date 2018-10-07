#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream is(S);
        string vowel = "aeiouAEIOU";
        int i = 1;
        string w,res;
        while(getline(is,w,' ')){
            if(vowel.find(w[0]) != string::npos){
                res += w+"ma";
                for(int j = 0;j < i;j++)
                    res += "a";
                res += " ";
            }
            else{
                res += w.substr(1)+w[0]+"ma";
                for(int j = 0;j < i;j++)
                    res += "a";
                res += " ";
            }
            i++;
        }
        return res.substr(0,res.size()-1);
    }
};