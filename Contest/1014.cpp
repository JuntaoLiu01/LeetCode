class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int res = 0,most = 0;
        for(int i = 0;i < n;i++){
            res = max(res,A[i]+most-i);
            most = max(most,A[i]+i);
        }
        return res;
    }
};