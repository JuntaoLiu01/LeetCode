class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int t = N%14;
        if(t==0)
            t = 14;
        vector<int> tmp(8,0);
        for(int i = 0;i < t;i++){
            for(int j = 1;j <= 6;j++)
                if(cells[j-1]==cells[j+1])
                    tmp[j] = 1;
                else
                    tmp[j] = 0;
            for(int j = 0;j < 8;j++)
                cells[j] = tmp[j];
        }
        return cells;
    }
};