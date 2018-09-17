class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int minPrice = prices[0],maxProfit = 0;
        for(int i = 1;i < n;i++){
            if(minPrice > prices[i])
                minPrice = prices[i];
            else
                maxProfit = max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};