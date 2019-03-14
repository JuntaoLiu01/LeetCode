
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = n/2;i >= 1;i--){
            if(n % i)
                continue;
            string cur = s.substr(0,i);
            bool f = true;
            for(int j = i;f && j < n;j += i){
                if(s.substr(j,i) != cur)
                    f = false;
            }
            if(f)
                return true;
        }
        return false;
    }
};