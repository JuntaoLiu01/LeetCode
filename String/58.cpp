class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int r = n-1;
        while(r >= 0 && s[r]==' ')
            r--;
        int l = r;
        while(l >= 0 && s[l]!=' ')
            l--;
        return r-l;
        
    }
};