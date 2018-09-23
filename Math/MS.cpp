#include <string>
using namespace std;

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
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        string res="0";
        int n1=num1.size(),n2=num2.size();
        
        for(int i=n1-1;i>=0;i--){
            if(num1[i]=='0')
                continue;
            string tmp;
            int s,si=0;
            int a1=num1[i]-'0';
            for(int j=0;j<n1-1-i;j++)
                tmp.push_back('0');
            for(int k=n2-1;k>=0;k--){
                int a2=num2[k]-'0';
                s = (a1*a2+si) %10;
                si = (a1*a2+si) /10;
                tmp.push_back(char(s+'0'));
            }
            if(si)
                tmp.push_back(char(si+'0'));
            reverse_string(tmp);
            res = addStrings(res,tmp);
        }
        return res;
    }
};

