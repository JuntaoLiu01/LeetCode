#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n < 1)
            return false;
        if(n < 3)
            return true;
        if(A[0] > A[n-1]){
            for(int i = 0;i < n-1;i++){
                if(A[i] < A[i+1])
                    return false;
            }
        }
        else if(A[0] < A[n-1]){
            for(int i = 0;i < n-1;i++){
                if(A[i] > A[i+1])
                    return false;
            }
        }
        else {
            for(int i = 0;i < n-1;i++){
                if(A[i] != A[i+1])
                    return false;
            }
        }
        return true;
    }
};