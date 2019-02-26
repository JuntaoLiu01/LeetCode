class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        map<int,int> sm;
        map<int,int> bm;
        int n = A.size();
        int end1,end2=n-1;
        int res = 0;
        for(int i = 0;i < n;i++){
            if(sm.size() < K){
                sm[A[i]]++;
                bm[A[i]]++;
                if(sm.size()==K)
                    end1=i;
            }
            else{
                if(bm.find(A[i])==bm.end()){
                    end2=i-1;
                    break;
                }
                bm[A[i]]++;
            }
        }
        if(sm.size() < K)
            return 0;
        res += end2-end1+1;
        for(int i = 1;i < n;i++){
            sm[A[i-1]]--;bm[A[i-1]]--;
            if(sm[A[i-1]]==0)
                sm.erase(A[i-1]);
            if(bm[A[i-1]]==0)
                bm.erase(A[i-1]);
            while(end1 < n-1){
                if(sm.size()==K)
                    break;
                end1++;
                sm[A[end1]]++;
            }
            if(sm.size() < K)
                break;
            while(end2 < n-1){
                if(bm.size() < K || bm.size()==K && bm.find(A[end2+1])!=bm.end()){
                    end2++;
                    bm[A[end2]]++;
                }
                else
                    break;
            }
            if(bm.size() < K)
                break;
            res += end2-end1+1;
        }
        return res;
    }
};