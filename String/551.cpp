class Solution {
public:
    bool checkRecord(string s) {
        int a = 0,l = 0;
        for(auto ch:s){
            if(ch=='A'){
                if(++a > 1)
                    return false;
                l = 0;
            }  
            else if(ch=='L'){
                l++;
                if(l > 2)
                    return false;
            }
            else
                l = 0;
        }
        return true;
    }
};