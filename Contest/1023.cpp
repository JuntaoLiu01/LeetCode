class Solution {
public:
    bool queryString(string S, int N) {
        if(N > 2400)
            return false;
        for(int i = 1;i <= N;i++){
            string t;
            int n = i;
            while(n){
                t += to_string(n%2);
                n /= 2;
            }
            reverse(t.begin(),t.end());
            if(S.find(t) == string::npos)
                return false;
        }
        return true;
    }
};