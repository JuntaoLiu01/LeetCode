class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int res = 0;
        for(int i = 0;i < houses.size();i++){
            int l = 0,r = heaters.size();
            int t = l;
            while(l < r){
                int mid = (l+r)/2;
                if(heaters[mid]==houses[i]){
                    t = mid;
                    break;
                }
                if(heaters[mid] < houses[i]){
                    l = mid+1;
                    t = l;
                }
                else{
                    r = mid;
                    t = r;
                }
            }
            int dis1 = t==heaters.size()?INT_MAX:heaters[t]-houses[i];
            int dis2 = t==0?INT_MAX:houses[i]-heaters[t-1];
            res = max(res,min(dis1,dis2));
        }
        return res;
    }
};