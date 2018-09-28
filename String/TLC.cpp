#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0;i < str.size();i++){
            if(isalpha(str[i]) && isupper(str[i]))
                str[i] = tolower(str[i]);
        }
        return str;
    }
};