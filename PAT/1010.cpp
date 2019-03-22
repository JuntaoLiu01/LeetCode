#include <iostream>
#include <cctype>
#include <math.h>
#include <algorithm>

using namespace std;

long long convert(string num,long long radix){
    long long sum = 0;
    int index = 0,temp = 0;
    for(int i = num.size()-1;i >=0;i--){
        temp = isdigit(num[i])?num[i]-'0':num[i]-'a'+10;
        sum += temp*pow(radix,index++);
    }
    return sum;
}

long long find(string num,long long target){
    char ch = *max_element(num.begin(),num.end());
    long long low = (isdigit(ch)?ch-'0':ch-'a'+10)+1;
    long long high = max(target,low);
    while(low <= high){
        long long mid = (low+high)/2;
        long long t = convert(num,mid);
        if(t==target)
            return mid;
        else if(t < 0 || t > target)
            high = mid-1;
        else
            low = mid+1;
    } 
    return -1;
}
int main(){
    string n1,n2;
    long long tag,radix;
    cin>>n1>>n2>>tag>>radix;
    long long num,res;
    if(tag==1){
        num = convert(n1,radix);
        res = find(n2,num);
    }   
    else{
        num = convert(n2,radix);
        res = find(n1,num);
    }
    if(res==-1)
        cout<<"Impossible";
    else 
        cout<<res;
    return 0;
}