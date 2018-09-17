// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left  = 1;
        long long right = n;
        while(left < right){
            long long tmp = left + right;
            long long mid = tmp/2;
            int t = guess(mid);
            if(t == 0)
                return mid;
            else if(t == 1)
                left = mid + 1;
            else
                right = mid - 1;
            cout<<left<<' '<<right<<endl;
        }
        return left;
    }
};