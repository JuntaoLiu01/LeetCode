#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int res = 0,pre = 0;
    for(int i =  0;i < n;i++){
        int f;
        cin>>f;
        int dif = f-pre;
        if(dif < 0)
            res += abs(dif) * 4 + 5;
        else    
            res += dif * 6 + 5;
        pre = f;
    }
    cout<<res;
    return 0;
}