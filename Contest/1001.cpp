class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        unordered_map<int,int> p;
        unordered_map<int,int> q;
        set<pair<int,int> > s;
        for(auto l:lamps){
            x[l[0]]++;
            y[l[1]]++;
            p[l[0]+l[1]]++;
            q[l[0]-l[1]]++;
            s.insert({l[0],l[1]});
        }
        vector<int> res;
        for(auto _q:quries){
            if(x[_q[0]] || y[_q[1]] || p[_q[0]+_q[1]] || q[_q[0]-_q[1]])
                res.push_back(1);
            else
                res.push_back(0);
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    pair<int,int> xy={_q[0]+i,_q[1]+j};
                    if(s.count(xy)){
                        x[xy.first]--;
                        y[xy.second]--;
                        p[xy.first+xy.second]--;
                        q[xy.first-xy.second]--;
                        s.erase(xy);
                    }
                }
            }
        }
        return res;

    }
};