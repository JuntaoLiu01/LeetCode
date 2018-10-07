#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        vector<int>& pair = pairs[0];
        int res = 1;
        for(int i = 1;i < pairs.size();i++){
            if(pairs[i][0] > pair[1]){
                res++;
                pair = pairs[i];
            }
        }
        return res;
    }
};