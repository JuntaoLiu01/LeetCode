class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0,minP = prices[0];
        for(int i = 1;i < n;i++){
            if(prices[i] < minP)
                minP = prices[i];
            res = max(res,prices[i]-minP);
        }
        return res;
    }
};