class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n,0);
        vector<int> res;
        for(int i = 0;i < n;i++)
            if(dfs(graph,state,i)==3)
                res.push_back(i);
        return res;

    }
    int dfs(vector<vector<int>>& graph,vector<int>& state,int a){
        if(state[a]==1)
            return state[a] = 2;
        if(state[a] != 0)
            return state[a];
        state[a] = 1;
        for(int nn:graph[a])
            if(dfs(graph,state,nn)==2)
                return state[a]=2;
        return state[a]=3;
    }
};