class Solution {
public:
    unordered_map<string,string> parent;
    string find(string p){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return parent[p];
    }
    void join(string a,string b){
        string pa = find(a);
        string pb = find(b);
        if(pa == pb)
            return;
        parent[pb] = pa;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> owner;
        for(auto account:accounts){
            for(int i = 1;i < account.size();i++){
                owner[account[i]] = account[0];
                if(!parent.count(account[i]))
                    parent[account[i]] = account[i];
                if(i > 1)
                    join(account[i-1],account[i]);
            }
        }
        unordered_map<string,set<string>> m;
        for(auto account:accounts){
            for(int i = 1;i < account.size();i++)
                m[find(account[i])].insert(account[i]);
        }
        vector<vector<string>> res;
        for(auto a:m){
            vector<string> v(a.second.begin(),a.second.end());
            v.insert(v.begin(),owner[a.first]);
            res.push_back(v);
        }
        return res;
    }
};