class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        vector<int> f(n,true);
        f[1] = false;
        for(int i = 2;i <= sqrt(n);i++){
            if(f[i]){
                for(int j = i*i;j < n;j += i)
                    f[j] = false;
            }
        }
        int res = 0;
        for(int i = 1;i < n;i++){
            if(f[i])
                res++;
        }
        return res;
     }
};