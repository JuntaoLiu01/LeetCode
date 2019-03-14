class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = -1,r = n;
        while(++l < --r){
            if(s[l]!=s[r])
                return check(s,l,r-1) || check(s,l+1,r);
        
        }
        return true;
    }
    bool check(string s,int l,int r){
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        return true;
    }
};