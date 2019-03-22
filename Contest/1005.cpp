class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        for(int& a:A){
            if(K > 0 && a < 0){
                a = -a;
                K--;
            }
        }
        return accumulate(A.begin(),A.end(),0)-(K%2 ? *min_element(A.begin(),A.end())*2:0);
    }
};