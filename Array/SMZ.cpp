#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool row_flag=false,col_flag=false;
        for(int j = 0;j < matrix[0].size();j++)
            if(!matrix[0][j])
                row_flag = true;
        for(int i = 0;i < matrix.size();i++)
            if(!matrix[i][0])
                col_flag = true;
        
        for(int i = 1;i < matrix.size();i++){
            for(int j = 1;j < matrix[0].size();j++){
                if(!matrix[i][j]){
                    for(int k = 0;k < j;k++)
                        matrix[i][k] = 0;
                    for(int m = 0;m < i;m++)
                        matrix[m][j] = 0;
                }
                else if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        if(row_flag){
            for(int j = 0;j < matrix[0].size();j++)
                matrix[0][j] = 0;
        }
        if(col_flag){
            for(int i = 0;i < matrix.size();i++)
                matrix[i][0] = 0;
        }
    }
};