class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        int n = S.size();
        for(int i = 0;i < n;i++){
            if(S[i]=='a' || S[i]=='b')
                s.push(S[i]);
            if(S[i]=='c'){
                if(s.size() < 2)
                    return false;
                char b = s.top();s.pop();
                char a = s.top();s.pop();
                if(b != 'b' || a != 'a')
                    return false;
            }
        }
        return s.empty()?true:false;
    }
};