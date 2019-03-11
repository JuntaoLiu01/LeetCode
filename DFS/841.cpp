class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(0,rooms,visited);
        for(int v:visited)
            if(!v)
                return false;
        return true;
        
    }
    void dfs(int id,vector<vector<int>> rooms,vector<int>& visited){
        if(visited[id])
            return;
        visited[id] = 1;
        for(auto room:rooms[id])
            dfs(room,rooms,visited);
    }
};