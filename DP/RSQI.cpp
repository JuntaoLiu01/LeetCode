#include <vector>
#include <iostream>

using namespace std;

class NumArray {    
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        int n = nums.size();
        sum = nums;
        for(int i = 1;i < n;i++)
            sum[i] += sum[i-1];
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return sum[j];
        else 
            return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(){
    vector<int> test;
    test.push_back(1),test.push_back(2),test.push_back(3);
    cout<<"at here"<<endl;
    NumArray num = NumArray(test);
    cout<<num.sum[0]<<endl;
    cout<<num.sumRange(0,2);
    return 0;
}