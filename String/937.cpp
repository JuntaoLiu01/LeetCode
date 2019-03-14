class Solution {
public:
    static bool compare(string& a,string& b){
        return a.substr(a.find(" ")) < b.substr(b.find(" "));
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter;
        vector<string> digit;
        for(auto log:logs){
            if(isalpha(log.back()))
                letter.push_back(log);
            else 
                digit.push_back(log);
        }
        sort(letter.begin(),letter.end(),compare);
        for(auto str:digit)
            letter.push_back(str);
        return letter;
    }
};