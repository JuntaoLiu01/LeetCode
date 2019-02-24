class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(Y <= X)
            return X-Y;
        if(Y%2 == 0)
            return brokenCalc(X,Y/2)+1;
        else
            return brokenCalc(X,Y+1)+1;
    }
};