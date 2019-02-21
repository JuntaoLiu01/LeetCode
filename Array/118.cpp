class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(!numRows)
            return res;
        vector<int> temp(1,1);
        res.push_back(temp);
        for(int i = 2; i <= numRows;i++){
            vector<int> t(i,1);
            for(int a = 1;a < i-1;a++)
                t[a] = res[i-2][a-1]+res[i-2][a];
            res.push_back(t);
        }
        return res;
    }
};