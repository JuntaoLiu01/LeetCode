class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        int t = INT_MAX;
        for(int i = n-1;i >= 2;i--){
            t = min(t,A[i]);
            if(A[i-2] > t)
                return false;
        }
        return true;
    }
};