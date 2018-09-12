#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0,hold = -prices[0];
        for(int i = 1;i < prices.size();i++){
            int tmp = sold;
            sold = max(sold,hold+prices[i]-fee);
            hold = max(hold,tmp-prices[i]);
        }
        return sold;
    }
};