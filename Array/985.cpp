class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int evensum = 0;
        for(int i=0;i < A.size();i++){
            if(A[i]%2==0)
                evensum += A[i];
        }
        vector<int> res;
        for(int i = 0;i < queries.size();i++){
            int val = queries[i][0],index = queries[i][1];
            if(A[index]%2){
                if(val%2)
                {
                    evensum += A[index] + val;
                    res.push_back(evensum);
                }
                else
                    res.push_back(evensum);   
            }
            else{
                if(A[index]%2)
                    res.push_back(evensum);
                else{
                    evensum += val;
                    res.push_back(evensum);
                }
            }
            A[index] += val;
        }
        return res;
    }
};