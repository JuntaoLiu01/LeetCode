class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 1;i <= sqrt(c/2);i++){
            if(fmod(sqrt(c-i*i),1)==0)
                return true;
        }
        return false;
    }
};