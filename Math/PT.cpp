class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long  base=1;
        while(base<n)
            base = base<<1;
        return base==n;
    }
};