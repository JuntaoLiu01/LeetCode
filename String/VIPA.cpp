#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string IPV6chars = "0123456789abcdefABCDEF";
    string validIPAddress(string IP) {
        stringstream IPV4(IP);
        stringstream IPV6(IP);
        int IPV4cnt = 0;
        int IPV6cnt = 0;
        string token;
        if(IP.find('.') != string::npos){
            while(getline(IPV4,token,'.')){
                IPV4cnt++;
                if(token.size() < 1 || token.size() > 3)
                    return "Neither";
                for(int i = 0;i < token.size();i++){
                    if((token[0]=='0'&&token.size()>1)||token[i]-'0'<0||token[i]-'0'>9)
                        return "Neither";
                }
                if(stoi(token)<0 || stoi(token)>255)
                    return "Neither";
            }
            if(IP[IP.size()-1]=='.')
                return "Neither";
            if(IPV4cnt==4)
                return "IPv4";
        }
        else if(IP.find(':') != string::npos){
            while(getline(IPV6,token,':')){
                IPV6cnt++;
                if(token.size() < 1 || token.size() > 4)
                    return "Neither";
                for(int i = 0; i < token.size();i++){
                    if(IPV6chars.find(token[i])==string::npos)
                        return "Neither";
                }
            }
            if(IP[IP.size()-1]==':')
                return "Neither";
            if(IPV6cnt==8)
                return "IPV6";
        }
        return "Neither";
    }
};