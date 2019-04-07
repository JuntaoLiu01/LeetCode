class Solution {
public:
    string baseNeg2(int n) {
        string res;
        while (n) {
            int r = abs(n % 2);
            if (r) --n;
            int q = n / -2;
            res += r + '0';
            n = q;
        }
        reverse(res.begin(), res.end());
        if (res.empty()) res += '0';

        return res;
   }
};