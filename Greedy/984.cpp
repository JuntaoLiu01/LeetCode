class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A==0)
            return string(B,'b');
        if(B==0)
            return string(A,'a');
        if(A > B)
            return "aab" + strWithout3a3b(A-2,B-1);
        if(B > A)
            return "bba" + strWithout3a3b(A-1,B-2);
        return "ab" + strWithout3a3b(A-1,B-1);
    }
};