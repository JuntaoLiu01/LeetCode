class Solution {
public:
    vector<string> splitByUper(string s){
        int i = 0;
        while(i < s.size() && islower(s[i]))
            i++;
        vector<string> res;
        if(i > 0)
            res.push_back(s.substr(0,i));
        else
            res.push_back("");
        int pre = i;
        i++;
        for(;i < s.size();i++){
            if(isupper(s[i])){
                res.push_back(s.substr(pre,i-pre));
                pre = i;
            }
        }
        if(i > pre)
            res.push_back(s.substr(pre,i-pre));
        return res;
    }
    bool isSub(string s,string t){
        int j = 0;
        for(int i = 0;i < t.size() && j < s.size();i++)
            if(s[j]==t[i])
                j++;
        return j==s.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<string> cmp  = splitByUper(pattern);
        vector<bool> res;
        for(string q:queries){
            vector<string> t = splitByUper(q);
            if(cmp.size() != t.size())
                res.push_back(false);
            else {
                int i = 0;
                for(i = 0;i < cmp.size();i++){
                    if(!isSub(cmp[i],t[i])){
                        res.push_back(false);
                        break;
                    }
                }
                if(i == cmp.size())
                    res.push_back(true);
            }   
        }
        return res;
    }
};