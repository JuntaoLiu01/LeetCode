#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    map<int,double> m;
    map<int,double> res;
    int n1,n2;
    int d;
    double k;
    cin>>n1;
    for(int i = 0;i < 2*n1;i+=2){
        cin>>d>>k;
        m[d] = k;
    }
    cin>>n2;
    for(int i = 0;i < 2*n2;i+=2){
        cin>>d>>k;
        for(auto p:m)
            res[p.first + d] += k*p.second;
    }
    int count = 0;
    vector<pair<int,double> > vp;
    for(auto p:res){
        if(p.second != 0.0){
            count++;
            vp.push_back(make_pair(p.first,p.second));
        }     
    }
    cout<<count;
    for(int i = vp.size()-1;i >= 0;i--){
        cout<<" "<<vp[i].first<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<vp[i].second;
    }
    return 0;
}