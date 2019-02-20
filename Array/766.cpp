class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        for(int a = 0;a < n;a++){
            int key = matrix[0][a];
            for(int i=1,j=a+1;i < m && j < n;i++,j++){
                if(matrix[i][j] != key)
                    return false;
            }
        }
        for(int b = 1;b < m;b++){
            int key = matrix[b][0];
            for(int i = b+1,j=1;i < m && j < n;i++,j++){
                if(matrix[i][j] != key)
                    return false;
            }
        }
        return true;
    }
};