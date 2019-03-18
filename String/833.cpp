class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<pair<int,int>> vp;
        for(int i = 0;i < n;i++)
            vp.push_back(make_pair(indexes[i],i));
        sort(vp.rbegin(),vp.rend());
        for(auto p:vp){
            int i = p.second;
            if(S.find(sources[i],indexes[i]) == indexes[i])
                S.replace(indexes[i],sources[i].size(),targets[i]);
        }
        return S;
    }
};