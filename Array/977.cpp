class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        for(int i = 0;i < n;i++){
            int k = A[i] * A[i];
            int j = i - 1;
            for(;j >= 0 && A[j] > k;j--)
                A[j+1] = A[j];
            A[j+1] = k;
        }
        return A;
    }
};


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int end = A.size()-1;
        int start = 0;
        vector<int> res;
        while(start <= end){
            if(A[start]*A[start] < A[end]*A[end]){
                res.push_back(A[end]*A[end]);
                end--;
            }
            else{
                res.push_back(A[start]*A[start]);
                start++;
            }
                
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};