#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse_string(string& str){
    int n = str.size();
    for(int i = 0;i < n/2;i++){
        char tmp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = tmp;
    }
}

void remove_zeros(string& str){
    int n = str.size();
    if(str=="0")
        return;
    int i = 0;
    for(;i < n;i++){
        if(str[i]!='0')
            break;
    }
    str = str.substr(i);
}

class BigInt{
public:
    string num;
    BigInt() {}
    BigInt(string Num):num(Num){}
    BigInt add(const BigInt& b){
        int n1=min(num.size(),b.num.size()),n2=max(num.size(),b.num.size());
        int l1=num.size(),l2=b.num.size();
        int s,si=0;
        string res;
        for(int i = 0;i < n1;i++){
            int a1 = num[l1-i-1]-'0',a2 = b.num[l2-i-1]-'0';
            if(a1+a2+si < 10){
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
                int a2=b.num[l2-i-1]-'0';
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
        else{
            for(int i = n1;i < n2;i++){
                int a1=num[l1-i-1]-'0';
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
        if(si==1)
        res.push_back('1');
        reverse_string(res);
        return BigInt(res);
    }
    int compare(const BigInt& b){
        int n1=num.size(),n2=b.num.size();
        if(n1<n2)
            return -1;
        if(n1>n2)
            return 1;
        for(int i = 0;i < n1;i++){
            if(num[i] < b.num[i])
                return -1;
            if(num[i] > b.num[i])
                return 1;
        }
        return 0;
    }
    BigInt subtract(const BigInt& b){
        int comp = compare(b);
        int n1=num.size(),n2=b.num.size();
        int s,si=0;
        if(!comp)
            return BigInt("0");
        string res;
        if(comp<0){
            for(int i = 0;i < n1;i++){
                int a1=num[n1-1-i]-'0',a2=b.num[n2-1-i]-'0';
                if(a2-a1-si>=0){
                    s = a2-a1-si;
                    si = 0;
                }
                else{
                    s = a2-a1-si+10;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
            for(int i = n1;i < n2;i++){
                int a2=b.num[n2-1-i]-'0';
                if(a2-si>=0){
                    s = a2-si;
                    si = 0;
                }
                else{
                    s = a2+10-si;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
            reverse_string(res);
            remove_zeros(res);
            string tmp="-";
            res = tmp.append(res);   
        }
        else{
            for(int i = 0;i < n2;i++){
                int a1=num[n1-1-i],a2=b.num[n2-1-i];
                if(a1-a2-si>=0){
                    s = a1-a2-si;
                    si = 0;
                }
                else{
                    s = a1+10-a2-si;
                    si = 1;
                }
                res.push_back(char(s+'0'));
            }
            for(int i = n2;i < n1;i++){
                int a1=num[n1-i-1];
                if(a1-si>=0){
                    s = a1-si;
                    si = 0;
                }
                else{
                    s = si+10-si;
                    si  = 1;
                }
                res.push_back(char(+'0'));
            }
            reverse_string(res);
            remove_zeros(res);
        }
        return BigInt(res);
    }
    BigInt multiply(const BigInt& b){
        int n1=num.size(),n2=b.num.size();
        BigInt res("0");
        for(int i = n2-1;i >= 0;i--){
            if(b.num[i]=='0')
                continue;
            string tmp;
            for(int j=0;j < n2-i-1;j++)
                tmp.push_back('0');
            int a2 = b.num[i]-'0';
            int s,si=0;
            for(int k=n1-1;k >= 0;k--){
                int a1 = num[k]-'0';
                s = (a1*a2+si) % 10;
                si = (a1*a2+si) / 10;
                tmp.push_back(char(s+'0'));
            }
            if(si)
                tmp.push_back(char(si+'0'));
            reverse_string(tmp);
            res = res.add(BigInt(tmp));
        }
        return res;
    }
    BigInt divide(const BigInt& b){
        int n1=num.size(),n2=b.num.size();
        if(n1 < n2)
            return BigInt("0");
        string res;
        BigInt div;
        div.num = num.substr(0,n2-1);
        for(int i = 0;i <=n1-n2;i++){
            int tmp = 0;
            div.num.push_back(num[i+n2-1]);
            while(div.compare(b)>=0){
                tmp++;
                div = div.subtract(b);
            }
            res.push_back(char(tmp+'0'));
        }
        remove_zeros(res);
        return BigInt(res);
    }
};

int main()
{
	BigInt a,b;
	char oper;
	cin >> a.num >> oper >> b.num;
	switch (oper)
	{
        case '+':
            std::cout << a.add(b).num;
            break;
        case '-':
            std::cout << a.subtract(b).num;
            break;
        case '*':
            std::cout << a.multiply(b).num;
            break;
        case '/':
            std::cout << a.divide(b).num;
            break;
        default: break;
	}
	return 0;
}