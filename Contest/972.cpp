class Solution {
public:
    auto convert(string s){
        // auto i = s.find('.');
        auto p = s.find('(');
        if(p != string::npos){
            string str = s.substr(p+1,s.size()-p-2);
            s = s.substr(0,p);
            while(s.size() < 16)
                s += str;
        }
        return stod(s);
    }
    bool isRationalEqual(string S, string T) {
        return abs(convert(S) - convert(T)) < 1e-10;
    }
};