class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(),n2 = b.size();
        int l = min(n1,n2);
        string res = "";
        int si = 0,s = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = 0;i < l;i++){
            int ka = a[i]-'0',kb = b[i]-'0';
            if(ka + kb + si < 2){
                s = ka+kb+si;
                si = 0;
            }
            else {
                s = ka+kb+si-2;
                si = 1;
            }
            res.push_back(char(s+'0'));
        }
        if(n1==l){
            for(int i = n1;i < n2;i++){
                int kb = b[i]-'0';
                if(kb+si < 2){
                    s = kb+si;
                    si = 0;
                }
                else{
                    s = kb+si-2;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }     
        }
        else {
            for(int i=n2;i < n1;i++){
                int ka = a[i]-'0';
                if(ka + si < 2){
                    s = ka+si;
                    si = 0;
                }
                else{
                    s = ka+si-2;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
        }
        if(si==1)
            res += "1";
        reverse(res.begin(),res.end());
        return res;
    }
};