class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end()),r = accumulate(weights.begin(),weights.end(),0)+1;
        while(l < r){
            int mid = (l+r)/2;
            int day = 1,sum = 0;
            for(int i = 0;i < n;i++){
                sum += weights[i];
                if(sum > mid){
                    sum = weights[i];
                    day++;
                }
            }
            if(day > D)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};