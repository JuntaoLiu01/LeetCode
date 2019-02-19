class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> even;
        vector<int> odd;
        for(int i = 0;i < n;i++){
            if(A[i] % 2)
                odd.push_back(A[i]);
            else
                even.push_back(A[i]);
        }
        int f1 = 0,f2 = 0;
        for(int i = 0;i < n;i++){
            if(i%2)
                A[i] = odd[f1++];
            else
                A[i] = even[f2++];
        }
        return A;
        
    }
};