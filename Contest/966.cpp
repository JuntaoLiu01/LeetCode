class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string,string> original;
        map<string,string> lower;
        map<string,string> vowel;
        for(string s:wordlist){
            original[s] = s;
            string l = toLower(s);
            if(!lower.count(l))
                lower[l] = s;
            string v = replaceVowels(l);
            if(!vowel.count(v))
                vowel[v] = s;
        }
        vector<string> res;
        for(string s:queries){
            if(original.count(s)){
                res.push_back(s);
                continue;
            }
            string l = toLower(s);
            if(lower.count(l)){
                res.push_back(lower[l]);
                continue;
            }
            string v = replaceVowels(l);
            if(vowel.count(v)){
                res.push_back(vowel[v]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
    string toLower(string s){
        string str(s);
        transform(s.begin(),s.end(),str.begin(),::tolower);
        return str;
    }
    string replaceVowels(string s){
        string str(s);
        for(char& ch:str){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                ch = '*';
        }
        return str;
    }
};