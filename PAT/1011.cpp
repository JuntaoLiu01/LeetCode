#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    vector<char> vc;
    vector<double> vi;
    double a,b,c;
    for(int i = 0;i < 3;i++){
        cin>>a>>b>>c;
        if(a > b && a > c){
            vc.push_back('W');
            vi.push_back(a);
        }
        else if(b > a && b > c){
            vc.push_back('T');
            vi.push_back(b);
        }
        else{
            vc.push_back('L');
            vi.push_back(c);
        }
    }
    double res = (vi[0]*vi[1]*vi[2]*0.65-1)*2;
    cout<<vc[0]<<" "<<vc[1]<<" "<<vc[2]<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<res;
    return 0;
}