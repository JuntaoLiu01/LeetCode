#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(),tmp.end());
        int res = 0,sum1 = 0,sum2 = 0;
        for(int i = 0;i < arr.size();i++){
            sum1 += arr[i];
            sum2 += tmp[i];
            if(sum1 == sum2)
                res++;
        }
        return res;
    }
};