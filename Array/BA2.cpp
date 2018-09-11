#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i = 1,j = n;
        vector<int> res;
        while(i <= j){
            if(k > 1)
                res.push_back(k--%2?i++:j--);
            else
                res.push_back(i++);
        }
        return res;
    }
};