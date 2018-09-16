class Solution {
private:
    string int2Bstr(int n){
        string s;
        for(int i = 31;i >= 0;i--){
            if(n & 1 << i)
                s += "1";
            else
                s += "0";
        }
        return s;
    }
public:
    int binaryGap(int N) {
        string s = int2Bstr(N);
        int  start = -1, res = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == "1")
            {
                if(start == -1)
                    start = i;
                else{
                    res = max(i - start,res);
                    start = i;
                }
            }
        }
        return ;
            
    }
};