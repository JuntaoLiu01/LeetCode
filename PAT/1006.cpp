#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,string> in;
    map<string,string> out;
    for(int i = 0;i < n;i++){
        string id,it,ot;
        cin>>id>>it>>ot;
        in[it] = id;
        out[ot] = id;
    }
    cout<<in.begin()->second<<" ";
    cout<<(--out.end())->second;
    return 0;
}