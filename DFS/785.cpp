class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& colors,int color,int node){
        if(colors[node])
            return colors[node]==color;
        colors[node]=color;
        for(int next:graph[node])
            if(!dfs(graph,colors,-color,next))
                return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        for(int i = 0;i < n;i++){
            if(!colors[i]){
                if(!dfs(graph,colors,1,i))
                    return false;
            }
        }
        return true;
    }
};