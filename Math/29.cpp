class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long m = abs((long long)dividend),n = abs((long long)divisor);
        int sign = ((dividend < 0) ^ (divisor < 0))?-1:1;
        long long res = 0;
        while(m >= n){
            long long t = n,p=1;
            while(m >= (t<<1)){
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign==1?res:-res;
    }
};