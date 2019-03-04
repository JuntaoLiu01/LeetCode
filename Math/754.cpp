class Solution {
public:
    int reachNumber(int target) {
        int res = 0;
        int sum = 0;
        while(sum < target || (sum-target)%2==1){
            res++;
            sum += res;
        }
        return res;
    }
};