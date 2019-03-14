class Solution {
public:
    bool isValid(string s) {
        stack<char> schar;
        for(char ch:s){
            if(ch=='(' || ch=='[' || ch=='{')
                schar.push(ch);
            if(ch==')'){
                if(schar.empty() || schar.top() != '(')
                    return false;
                schar.pop();
            }
            if(ch==']'){
                if(schar.empty() || schar.top() != '[')
                    return false;
                schar.pop();
            }
            if(ch=='}'){
                if(schar.empty() || schar.top() != '{')
                    return false;
                schar.pop();
            }
        }
        return schar.empty();
    }
};