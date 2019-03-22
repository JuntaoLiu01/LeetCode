#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++)
        cin>>nums[i];
    int res = -1,cur = 0;
    int l = 0,r = n-1,tl = 0;
    for(int i = 0;i < n;i++){
        cur += nums[i];
        if(cur < 0){
            cur = 0;
            tl = i+1;
        }
        else if(cur > res){
            res = cur;
            r = i;
            l = tl;
        }
    }
    if(res < 0)
        res = 0;
    cout<<res<<" "<<nums[l]<<" "<<nums[r]; 
    return 0;
}