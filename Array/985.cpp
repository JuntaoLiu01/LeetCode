class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int evensum = 0;
        for(auto num:A){
            if(num%2==0)
                evensum += num;          
        }
        for(auto q:queries){
            int val = q[0],index = q[1];
            if(val%2==0){
                if(A[index]%2==0){
                    evensum += val;
                    res.push_back(evensum);
                }
                else
                    res.push_back(evensum);
            }
            else{
                if(A[index]%2==0){
                    evensum -= A[index];
                    res.push_back(evensum);
                }                   
                else{
                    evensum += val+A[index];
                    res.push_back(evensum);
                }
            }
            A[index] += val;
        }
        return res;
    }
};