class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        vector<int> sum(n,0);
        for(int i = 0;i < n;i++){
            if(i == 0)
                sum[i] = A[i];
            else
                sum[i] = A[i]+sum[i-1];
        }
        if(sum[n-1]%3)
            return false;
        int t = sum[n-1]/3;
        int i = -1,j = -1;
        for(int index = 0;index < n;index++){
            if(i == -1){
                if(sum[index]==t)
                    i = index;
            }
            else if(j == -1){
                if(sum[index]-sum[i]==t)
                    j = index;
            }
        }
        // cout<<i<<" "<<j<<endl;
        if(j == -1)
            return false;
        return sum[n-1]-sum[j]==t;
    }
};