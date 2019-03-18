class Solution {
public:
    int mySqrt(int x) {
        long long l = 0,r = x;
        long long res = l;
        while(l <= r){
            long long m = (l+r)/2;
            if(m*m == x)
                return m;
            else if(m*m > x){
                r = m-1;
                res = r;
            }
            else {
                res = m;
                l = m+1;
            }
        }
        return res;
    }
};