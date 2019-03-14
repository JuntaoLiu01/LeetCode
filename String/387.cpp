class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if(n==1)
            return 0;
        unordered_set<char> us; 
        for(int i = 0;i < n-1;i++){
            if(!us.count(s[i]) && s.substr(i+1).find(s[i])==string::npos)
                return i;
            us.insert(s[i]);
        }
        return us.count(s.back())?-1:n-1;
    }
};