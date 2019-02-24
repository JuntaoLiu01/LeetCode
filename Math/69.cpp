class Solution {
public:
    int mySqrt(int x) {
        long long l = 1,h = x;
        int res = 0;
        while(l <= h){
            long long mid = (l+h)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x){
                res = mid;
                l = mid+1;
            }
            else{
                h = mid -1;
                res = h;
            }
        }
        return res;
    }
};