#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        bool ret = false;
        int left = 0,right = m-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[mid][0] > target)
                right = mid-1;
            else if(matrix[mid][n-1] < target)
                left = mid+1;
            else{
                int cur_left = 0,cur_right = n-1;
                while(cur_left <= cur_right){
                    int cur_mid = (cur_left + cur_right) / 2;
                    if(matrix[mid][cur_mid] == target){
                        ret = true;
                        return ret;
                    }
                    else if(matrix[mid][cur_mid] < target)
                        cur_left = cur_mid+1;
                    else
                        cur_right = cur_mid-1;
                }
                return ret;
            }
        }
        return ret;
    }
};

int main(){
    int a[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    vector<vector<int> > tmp;
    tmp.resize(3);
    for(int i = 0;i < 3;i++){
        tmp[i].resize(4);
        for (int j = 0;j < 4;j++){
            tmp[i][j] = a[i][j];
        }
    }
    int target = 60;
    Solution s = Solution();
    bool ret = s.searchMatrix(tmp,target);
    cout<<ret<<endl;
    return 0;
}