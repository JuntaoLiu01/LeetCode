class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        int pos = n;
        vector<int> res;
        for(;pos > 0;pos--){
            int i = 0;
            for(;i < pos;i++)
                if(A[i] == pos)
                    break;
            reverse(A.begin(),A.begin()+i+1);
            res.push_back(i+1);
            reverse(A.begin(),A.begin()+pos);
            res.push_back(pos);
        }
        return res;
    }
};
