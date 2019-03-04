class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int n = A.size();
        // decreasing order
        for(int i = 0;i < n;i++){
            if(s.empty() || A[i] < A[s.top()])
                s.push(i);
        }
        int res = 0;

        for(int i=n-1;i >= 0;i--){
            while(!s.empty() && A[i] >= A[s.top()]){
                res = max(i-s.top(),res);
                s.pop();
            }
        }
        return res;
    }
};