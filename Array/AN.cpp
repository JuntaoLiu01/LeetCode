#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<bool> visited(n,false);
        for(int i = 0;i < n;i++){
            if(visited[i])
                continue;
            int j = i,cnt = 0;
            while(cnt ==0 || j != i){
                visited[j] = true;
                cnt++;
                j = nums[j];
            }
            res = max(res,cnt);
        }
        return res;
    }
};