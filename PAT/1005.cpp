#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char,string> m = {{'0',"zero"},{'1',"one"},{'2',"two"},{'3',"three"},{'4',"four"},{'5',"five"},{'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"}};

int main(){
    string t;
    cin>>t;
    int sum = 0;
    for(char ch:t)
        sum += ch-'0';
    string str = to_string(sum);
    for(int i = 0;i < str.size();i++){
        if(i > 0)
            cout<<" "<<m[str[i]];
        else
            cout<<m[str[i]];
    }
    return 0;
}