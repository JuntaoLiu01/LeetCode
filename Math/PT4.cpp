#include <math.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log(num)/log(4),1) == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return !(num&(num-1)) && !(num&0x55555555);
    }
};