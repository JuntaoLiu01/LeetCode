class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = *max_element(A.begin(),A.end());
        vector<int> count(n+1);
        for(int a:A)
            for(int b:A)
                count[a&b]++;
        int res = 0;
        for(int a:A)
            for(int i = 0;i <= n;i++)
                if(a&i==0)
                    res += count[i];
        return res;     
    }
};