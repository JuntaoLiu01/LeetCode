#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0,sumB = 0;
        for(int i = 0;i < A.size();i++)
            sumA += A[i];
        for(int i = 0;i < B.size();i++)
            sumB += B[i];        
        int dis = sumA-sumB;
        for(int i = 0;i < A.size();i++)
            for(int j = 0;j < B.size();j++){
                if(2*(A[i]-B[j]) == dis)
                    return {A[i],B[j]};
            }
        return {};
    }
};