class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        for(string path:paths){
            istringstream is(path);
            vector<string> t;
            string str;
            while(getline(is,str,' '))
                t.push_back(str);
            for(int i = 1;i < t.size();i++){
                size_t found = t[i].find("(");
                string file = t[0]+'/'+t[i].substr(0,found);
                m[t[i].substr(found+1,t[i].size()-found-2)].push_back(file);
            }
        }
        vector<vector<string>> res;
        for(auto p:m){
            if(p.second.size()>1)
                res.push_back(p.second);
        }
        return res;
    }
};