class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        for(int i = 0;i < size;i++){
            int len = A[i].size();
            for(int j = 0;j <= (len-1)/2;j++){
                int t1 = 1-A[i][j];
                int t2 = 1-A[i][len-j-1];
                A[i][j] = t2;
                A[i][len-j-1] = t1;
            }
        }
        return A;       
    }
};