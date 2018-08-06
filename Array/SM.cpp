#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m == 0)
            return ret;
        int n = matrix[0].size();
        if(n == 0)
            return ret;

        int x=0,y=0,count=0;
        while(count < m*n){
            while(count < m*n && y < n-x){
                ret.push_back(matrix[x][y++]);
                count++;
            }
            x++,y--;

            while(count < m*n && x < m-(n-y)+1){
                ret.push_back(matrix[x++][y]);
                count++;
            }
            x--,y--;

            while(count < m*n && y >= m-x-1){
                ret.push_back(matrix[x][y--]);
                count++;
            }
            x--;y++;

            while(count < m*n && x >= y+1){
                ret.push_back(matrix[x--][y]);
                count++;
            }
            x++;y++;
        }
        return ret;
    }
};
