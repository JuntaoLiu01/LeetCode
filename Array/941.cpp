class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<=2) return false;
    
        for(int i=1;i<A.size()-1;i++){
            if((A[i+1]-A[i]>0 && A[i]-A[i-1]<0) || A[i+1]==A[i] || A[i-1] == A[i])                      return false;           
        }
    
        if(A[A.size()-1]>=A[A.size()-2] || A[0]>=A[1]) 
            return false;
        return true;
    }
};