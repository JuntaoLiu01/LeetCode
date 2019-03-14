class Solution {
public:
    void reverse_string(string& str){
        int n = str.size();
        for(int i = 0;i < n/2;i++)
            swap(str[i],str[n-1-i]);
    }
    string addStrings(string num1, string num2) {
        int n1=min(num1.size(),num2.size()),n2=max(num1.size(),num2.size());
        int l1=num1.size(),l2=num2.size();
        int s,si = 0;
        string res;
        for(int i = 0;i < n1;i++){
            int a1=num1[l1-i-1]-'0';
            int a2=num2[l2-i-1]-'0';
            if(a1+a2+si<10){
                s = a1+a2+si;
                si = 0;
            }
            else{
                s = a1+a2+si-10;
                si = 1;
            }
            res.push_back(char(s+'0'));
        }
        if(l1==n1){
            for(int i = n1;i < n2;i++){
                int a2=num2[l2-i-1]-'0';
                if(a2+si<10){
                    s = a2+si;
                    si = 0;
                }
                else{
                    s = a2+si-10;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
        }
        if(l2==n1){
            for(int i = n1;i < n2;i++){
                int a1=num1[l1-i-1]-'0';
                if(a1+si<10){
                    s = a1+si;
                    si = 0;
                }
                else{
                    s = a1+si-10;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
        }
        if(si)
            res.push_back('1');
        reverse_string(res);
        return res;
    }
};