class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(string str:strs){
            string t = str;
            sort(t.begin(),t.end());
            m[t].push_back(str);
        }
        vector<vector<string>> res;
        for(auto p:m)
            res.push_back(p.second);
        return res;
    }
};