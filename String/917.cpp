class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        if(n==0)
            return "";
        int l = 0,r = n-1;
        while(!isalpha(S[l]))
            l++;
        while(!isalpha(S[r]))
            r--;
        while(l <= r){
            swap(S[r--],S[l++]);
            while(!isalpha(S[l]))
                l++;
            while(!isalpha(S[r]))
                r--;             
        }
        return S;
    }
};