class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n-1,true);
        flag[0]=false;
        for(int i = 2;i <= sqrt(n);i++){
            if(flag[i-1]){
                for(int j = i*i;j < n;j+=i)
                    flag[j-1]=false;
            }
        }
        int res = 0;
        for(int i = 0;i < n-1;i++){
            if(flag[i])
                res++;
        }
        return res;
    }
};