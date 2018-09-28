#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string f(string w){
        unordered_map<char,int> m;
        for(char ch:w){
            if(!m.count(ch))
                m[ch] = m.size();
        }
        string res;
        for(char ch:w){
            res += char('a'+m[ch]);
        }
        return res;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string fp = f(pattern);
        vector<string> res;
        for(string w:words){
            if(f(w) == fp)
                res.push_back(w);
        }
        return res;
    }
};