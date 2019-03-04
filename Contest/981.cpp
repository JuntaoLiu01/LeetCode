class TimeMap {
public:
    map<string,vector<pair<int,string>>> m;
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
            return "";
        if(m[key][0].first > timestamp)
            return "";
        int n = m[key].size();
        int l = 0,r = n-1;
        while(l < r-1){
            int mid = (l+r)/2;
            if(m[key][mid].first <= timestamp)
                l = mid;
            else
                r = mid-1;
        }
        if(m[key][r].first <= timestamp)
            return m[key][r].second;
        return m[key][l].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */