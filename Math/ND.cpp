#include <math.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9)
            return n;
        int sum = 0,preSum;
        int i = 1;
        for(;i <= 8;i++){
            preSum = sum;
            if(i == 1)
                sum += i*pow(10,i)-1;
            else 
                sum += i*pow(10,i);
            if(n < sum)
                break;
        }
        int diff;
        if(i==9)
            diff = n-sum;
        else
            diff = n-preSum;
        int base = pow(10,i-1);
        int num = base + (diff-1)/i;
        int th = (diff-1)%i;
        for(int j = i-1;j >= 0;j--){
            if(j == th)
                return num%10;
            num = num/10;
        }
        return 0;
    }
};