class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for(int i = 0; i < (int)A.size() - 2; i++) {
            if(A[i] + A[i + 1] > A[i + 2]) {
                res = A[i] + A[i + 1] + A[i + 2];
            }
        }
        return res;
    }
};