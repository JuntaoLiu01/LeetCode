class Solution {
public:
    int helper(int n){
        if(n == 1)
            return 1;
        if(n==2)
            return 2;
        return n*(n-1)/(n-2);
    }
    int clumsy(int N) {
        bool f = true;
        int res = 0;
        for(int i = N;i >= 1;i-=4){
            int t = helper(i);
            if(f){
                res += t;
                f = false;
            }  
            else
                res -= t;
            if(i - 3 >= 1)
                res += i-3;
        }
        return res;
    }
};