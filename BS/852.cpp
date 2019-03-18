class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int l = 0,r = n;
        while(l < r){
            int m = (l+r)/2;
            if(A[m] < A[m+1])
                l = m+1;
            else
                r = m;
        }
        return l;
    }
};