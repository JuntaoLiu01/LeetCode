class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> t;
        for(string str:timePoints){
            int h = stoi(str.substr(0,2));
            int m = stoi(str.substr(3,2));
            t.push_back(h*60+m);
            t.push_back(1440+h*60+m);
        }
        int res = INT_MAX;
        sort(t.begin(),t.end());
        for(int i = 1;i < t.size();i++)
            res = min(t[i]-t[i-1],res);
        return res;
    }
};