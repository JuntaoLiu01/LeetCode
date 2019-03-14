class Solution {
char* morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for(string str:words){
            string tmp;
            for(int j = 0;j < str.size();j++)
                tmp += morse[str[j]-'a'];
            s.insert(tmp);
        }
        return s.size();
    }
};
