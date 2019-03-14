class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        if(strs.size()==0)
            return res;
        for(int k = 0;;k++){
            char ch = strs[0][k];
            for(int i = 0;i < strs.size();i++){
                if(k==strs[i].size())
                    return res;
                if(strs[i][k] != ch)
                    return res;
            }
            res.push_back(ch);
        }
        return res;
    }
};