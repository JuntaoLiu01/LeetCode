class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> va(6,0);
        vector<int> vb(6,0);
        vector<int> ab(6,0);
        for(int i = 0;i < n;i++){
            va[A[i]-1]++;
            vb[B[i]-1]++;
            if(A[i]==B[i])
                ab[A[i]-1]++;
            else{
                ab[A[i]-1]++;
                ab[B[i]-1]++;
            }
        }
        for(int i = 0;i < 6;i++){
            if(ab[i] >= n)
                return n-max(va[i],vb[i]);
        }
        return -1;
    }
};



class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = INT_MAX;
        for(int i = 1;i <= 6;i++){
            bool f = true;
            int countA = 0,countB = 0;
            for(int j = 0;j < A.size();j++){
                if(A[j] != i && B[j] != i){
                    f = false;
                    break;
                }
                if(A[j]==i && B[j]==i)
                    continue;
                if(A[j] == i)
                    countA++;
                else 
                    countB++;
            }
            if(f)
                res = min(res,min(countA,countB));
        }
        return res==INT_MAX?-1:res;
    }
};