class Solution {
public:
    int find(vector<int>& root,int p){
        while(root[p] != -1)
            p = root[p];
        return p;
    }
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        vector<int> root(2001,-1);
        for(auto edge:edges){
            int x = find(root,edge[0]),y = find(root,edge[1]);
            if(x == y)
                return edge;
            root[y] = x;
        }
        return {};
    }
};