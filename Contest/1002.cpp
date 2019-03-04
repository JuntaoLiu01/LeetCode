class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char,int> m;
        for(char ch:A[0])
            m[ch]++;
        int n = A.size();
        for(int i = 1;i < n;i++){
            map<char,int> t;
            for(int j = 0;j < A[i].size();j++){
                if(m.find(A[i][j]) != m.end() && m[A[i][j]]){
                    t[A[i][j]]++;
                    m[A[i][j]]--;
                }
            }
            m = t;
        }
        vector<string> res;
        for(auto a:m){
            for(int i = 0;i < a.second;i++){
                res.push_back(string(1,a.first));
            }           
        }
        return res;
    }
};