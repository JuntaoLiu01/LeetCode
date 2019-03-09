/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> m;
        unordered_set<int> s;
        for(auto e:employees)
            m[e->id] = e;
        return dfs(id,m,s);
    }
    int dfs(int id,unordered_map<int,Employee*>& m,unordered_set<int>& s){
        if(s.count(id))
            return 0;
        s.insert(id);
        int res = m[id]->importance;
        for(int i = 0;i < m[id]->subordinates.size();i++)
            res += dfs(m[id]->subordinates[i],m,s);
        return res;
    }
};