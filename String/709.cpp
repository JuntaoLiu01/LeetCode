class Solution {
public:
    string toLowerCase(string str) {
        string res;
        res.resize(str.size());
        transform(str.begin(),str.end(),res.begin(),::tolower);
        return res;
    }
};

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