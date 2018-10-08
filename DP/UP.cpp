class Solution {
public:
    int zuhe(int n,int k){
        int i = n,j = k;
        int t1=1,t2=1;
        while(i >= n-k+1){
            t1 *= i;
            i--;
        }  
        while(j >= 1){
            t2 *= j;
            j--;
        }

        return t1/t2;
    }
};