class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int,vector<pair<int,int>>> m;
        for(auto p:points)
            m[p[0]*p[0] + p[1]*p[1]].emplace_back(p[0],p[1]);
        int count = 0;
        map<int,vector<pair<int,int>>>::iterator it=m.begin();
        vector<vector<int>> res;
        while(count < K){
            for(int i = 0;i < it->second.size();i++){
                res.push_back({it->second[i].first,it->second[i].second});
                count++;
            }
            it++;
        }
        return res;
    }
};