#include <string>
#include <vector>
#include <set>

using namespace std;

char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for(int i = 0;i < words.size();i++){
            string str = words[i];
            string tmp;
            for(int j = 0;j < str.size();j++)
                tmp += morse[str[j]-'a'];
            s.insert(tmp);
        }
        return s.size();
    }
};
