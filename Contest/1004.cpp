class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0,res = 0,zero = 0;
        for(int right = 0;right < n;right++){
            if(A[right]==0)
                zero++;
            while(zero > K){
                if(A[left++]==0)
                    zero--;
            }
            res = max(res,right-left+1);
        }
    }
};