class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> g;
        g.resize(n);
        for(auto rich:richer)
            g[rich[1]].push_back(rich[0]);
        vector<int> res;
        vector<int> visited;
        for(int i = 0;i < n;i++){
            int id = 0;
            int vol = 501;
            visited.assign(n,0);
            dfs(visited,g,quiet,vol,id,i);
            res.push_back(id);
        }
        return res;
    }

    void dfs(vector<int>& visited,vector<vector<int> >& g,vector<int>& quiet,int &vol,int &id,int x){
        visited[x] = 1;
        if(vol > quiet[x]){
            id  = x;
            vol = quiet[x];
        }
        for(int i:g[x])
            if(!visited[i])
                dfs(visited,g,quiet,vol,id,i);
    }
};