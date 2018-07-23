#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> tmp(n,0);
        vector<vector<int> > ret(n,tmp);
        int x = 0,y = 0;
        int count = 1;
        while(count <= n*n){
            for(;y < n-x;y++)
                ret[x][y] = count++;

            for(x=x+1;x < y;x++)
                ret[x][y-1]  = count++;

            for(y=y-2;y >= n-x;y--)
                ret[x-1][y] = count++;
            
            for(x=x-2;x >= y+2;x--)
                ret[x][y+1] = count++;
            y = y+1;
            x++,y++;
        }
        return ret;
    }
};

int main(){
    int n = 3;
    Solution s = Solution();
    vector<vector<int> > ret = s.generateMatrix(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cout<<ret[i][j]<<'\t';
        cout<<endl;
    }
        

}