class Solution {
public:
    int getSubSum(vector<int> sum,int i,int j){
        if(i == 0)
            return sum[j];
        return sum[j]-sum[i-1];
    }
    int helper(vector<int> sum,int n,int L,int M){
        int res = getSubSum(sum,n-L-M,n-1);
        pair<int,int> secondSub = make_pair(n-M,getSubSum(sum,n-M,n-1));
        for(int i = n-L-M-1;i >= 0;i--){
            int cur = getSubSum(sum,i+L,i+L+M-1);
            if(cur >= secondSub.second)
                secondSub = make_pair(i+L,cur);
            cur = getSubSum(sum,i,i+L-1)+secondSub.second;
            if(cur >= res)
                res = cur;
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> sum(n,0);
        sum[0] = A[0];
        for(int i = 1;i < n;i++)
            sum[i] = sum[i-1]+A[i];
        return max(helper(sum,n,L,M),helper(sum,n,M,L));
    }
};