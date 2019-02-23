class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> mod(K,0);
        int n = A.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += A[i];
            mod[((sum%K)+K)%K] += 1;
        }
        int ans = 0;
        for(int i = 0;i < K;i++){
            if(mod[i] > 1)
               ans += ((mod[i]-1)*mod[i])/2; 
        }
        ans += mod[0];    
        return ans;         
    }
};