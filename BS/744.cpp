class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0,r = n;
        while(l < r){
            int m = (l+r)/2;
            if(letters[m] > target)
                r = m;
            else 
                l = m+1;
        }
        if(r == n)
            return letters[0];
        return letters[r];
    }
};