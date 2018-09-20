class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = -1;
        for(int j=0;j < A.size();j++){
            if(!(A[i]%2)){
                i++;
                swap(A[i],A[j]);
            }
        }
        return A;
    }
};