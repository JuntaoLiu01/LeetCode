class Solution {
public:
    unordered_map<string,pair<string,double>> parent;
    pair<string, double> find(string p){
        if(parent[p].first != p){
            auto t = find(parent[p].first);
            parent[p].first = t.first;
            parent[p].second *= t.second;
        }
        return parent[p];
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
        for(int i = 0;i < n;i++){
            string a = equations[i].first;
            string b = equations[i].second;
            double k = values[i];
            if(!parent.count(a) && !parent.count(b)){
                parent[a] = {b,k};
                parent[b] = {b,1.0};
            }
            else if(!parent.count(a)){
                parent[a] = {b,k};
            }
            else if(!parent.count(b)){
                parent[b] = {a,1.0/k};
            }
            else{
                auto pa = find(a);
                auto pb = find(b);
                parent[pa.first] = {pb.first, k / pa.second * pb.second};
            }
        }
        vector<double> res;
        for(auto q:queries){
            string x = q.first;
            string y = q.second;
            if(!parent.count(x) || !parent.count(y)){
                res.push_back(-1.0);
                continue;
            }    
            auto px = find(x);
            auto py = find(y);
            if(px.first != py.first)
                res.push_back(-1.0);
            else
                res.push_back(px.second/py.second);
        }
        return res;
    }
};