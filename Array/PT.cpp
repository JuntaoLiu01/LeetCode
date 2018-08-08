#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows < 1)
            return ret;
        ret.resize(numRows);
        for(int i = 0;i < numRows;i++){
            ret[i].resize(i+1);
            if(i == 0)
                ret[i][0] = 1;
            else{
                ret[i][0] = 1,ret[i][i] = 1;
                for(int j = 1;j < i;j++)
                    ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
        return ret;
    }
};