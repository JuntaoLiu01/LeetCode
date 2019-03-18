class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> m;
        for(char ch:T)
            m[ch]++;
        string res = "";
        for(char ch:S){
            res += string(m[ch],ch);
            m[ch] = 0;
        }
        for(auto p:m)
            res += string(p.second,p.first);
        return res;
    }
};