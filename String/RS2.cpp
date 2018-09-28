#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0;i < n;i += 2*k){
            int minBorder = min(i+k,n);
            for(int j = 0;j < (minBorder-i)/2;j++)
                swap(s[i+j],s[minBorder-j-1]);
        }
        return s;
    }
    
};