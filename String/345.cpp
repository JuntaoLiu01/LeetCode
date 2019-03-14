class Solution {
public:
    set<char> schar = {'a','e','i','o','u','A','E','I','O','U'};
    string reverseVowels(string s) {
        int l = 0,r = s.size()-1;
        while(l < r){
            while(!schar.count(s[l]) && l < r)
                l++;
            while(!schar.count(s[r]) &&  l < r)
                r--;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};