class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses,0);
        for(auto p:prerequisites){
            in[p.first]++;
            graph[p.second].push_back(p.first);
        }
        int count = 0;
        vector<int> res;
        while(count < numCourses){
            bool f = true;
            int i = 0;
            for(;i < numCourses;i++){
                if(in[i] == 0){
                    f = false;
                    res.push_back(i);
                    in[i] = -1;
                    break;
                }
            }
            if(f)
                return {};
            for(int x:graph[i])
                in[x]--;
            count++;
        }
        return res;
    }
};