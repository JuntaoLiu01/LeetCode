class Solution {
public:
    vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for(auto p:prerequisites)
            graph[p.first].push_back(p.second);
        vector<int> v(numCourses,0);
        for(int i = 0;i < numCourses;i++)
            if(!dfs(v,i))
                return false;
        return true;
    }

    bool dfs(vector<int>& v,int x){
        if(v[x]==1)
            return false;
        if(v[x]==2)
            return true;
        v[x]=1;
        for(int n:graph[x])
            if(!dfs(v,n))
                return false;
        v[x] = 2;
        return true;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses,0);
        for(auto p:prerequisites){
            in[p.first]++;
            graph[p.second].push_back(p.first);
        }
        int count = 0;
        while(count < numCourses){
            bool f = true;
            int i = 0;
            for(i = 0;i < numCourses;i++)
                if(in[i]==0){
                    f = false;
                    in[i] = -1;
                    break;
                }
            if(f)
                return false;
            for(int x:graph[i])
                in[x]--;
            count++;
        }
        return true;
    }
};