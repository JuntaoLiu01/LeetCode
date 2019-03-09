class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int res = 0;
        int p = 0;
        int l = 0,r = tokens.size()-1;
        while(l <= r){
            if(P >= tokens[l]){
                res = max(res,++p);
                P -= tokens[l++];
            }
            else if(p > 0){
                p--;
                P += tokens[r--];
            }
            else
                break;
        }
        return res;
    }
};