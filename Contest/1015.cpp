class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int res = 0,cnt = 0;
        for(int i = 0;i < 1e6;i++){
            res = (res*10+1)%K;
            cnt++;
            if(res == 0)
                return cnt;
        }
        return -1;
    }
};