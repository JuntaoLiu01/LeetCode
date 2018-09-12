#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0,n = arr.size();
        for(int i = 0;i < n;i++){
            int cur = arr[i],j = i+1;
            for(;j <= cur;j++){
                cur = max(arr[j],cur);
                if(cur > arr.back())
                    return res+1;
            }
            res++;
            i = j-1;
        }
        return res;
    }
};