class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int res = 0;
        for(int i = 0;i < n;i++)
            res += price[i]*needs[i];
        for(auto offer:special){
            bool f = true;
            for(int i = 0;i < n;i++){
                if(offer[i] > needs[i])
                    f = false;
                needs[i] -= offer[i];
            }
            if(f)
                res = min(res,shoppingOffers(price,special,needs)+offer.back());
            for(int i = 0;i < n;i++)
                needs[i] += offer[i];
        }
        return res;
    }
};