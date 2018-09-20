class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        for(auto op : ops){
            m = min(m,ops[0]);
            n = min(n,ops[1]);
        }
        return m*n;
    }
};