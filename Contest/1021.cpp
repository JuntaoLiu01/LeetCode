class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        int pre = 0;
        string res;
        for(int i = 0;i < S.size();i++){
            if(S[i]=='(')
                count++;
            if(S[i]==')')
                count--;
            if(count == 0){
                res += S.substr(pre+1,i-pre-1);
                pre = i+1;
            }
        }
        return res;
    }
};