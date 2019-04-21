class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> t;
        for(int i = 0;i < n;i++)
            t.push_back({costs[i][0]-costs[i][1],i});
        sort(t.begin(),t.end());
        int sum = 0;
        for(int i = 0;i < n/2;i++)
            sum += costs[t[i][1]][0];
        for(int j = n/2;j < n;j++)
            sum += costs[t[j][1]][1];
        return sum;
    }
};