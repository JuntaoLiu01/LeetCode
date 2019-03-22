#include <iostream>
#include <string>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    string t = to_string(a+b);
    int n = t.size();
    for(int i = 0;i < n;i++){
        cout<<t[i];
        if(t[i]=='-')
            continue;
        if((i+1)%3==n%3 && i != n-1)
            cout<<",";
    }
    return 0;
}