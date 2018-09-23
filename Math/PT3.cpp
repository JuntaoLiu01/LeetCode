#include <math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxNum = pow(3,19);
        return (n >0 && !(maxNum%n));
    }
};