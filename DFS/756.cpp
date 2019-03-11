class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,unordered_set<char>> m;
        for(string str:allowed)
            m[str.substr(0,2)].insert(str[2]);
        return dfs(bottom,"",m);
    }
    bool dfs(string bottom,string above,unordered_map<string,unordered_set<char>> m){
        if(bottom.size()==2 && above.size()==1)
            return true;
        if(above.size()==bottom.size()-1)
            return dfs(above,"",m);
        int pos=above.size();
        string base = bottom.substr(pos,2);
        if(m.count(base)){
            for(char ch:m[base])
                if(dfs(bottom,above+string(1,ch),m))
                    return true;
        }
        return false;
    }
};