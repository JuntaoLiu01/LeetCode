class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        vector<int> res(N+1);
        res[0] = 0;res[1] = 1;
        for(int i = 2;i <= N;i++)
            res[i] = res[i-1] + res[i-2];
        return res[N];
    }
};