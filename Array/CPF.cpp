#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        for(int i = 0;i < flowerbed.size();i++){
            if(res >= n)
                return true;
            if(flowerbed[i] == 0){
                if(i == 0 || flowerbed[i-1] != 1)
                    if(i == flowerbed.size()-1 || flowerbed[i+1] != 1){
                        res++;
                        flowerbed[i] = 1;
                    }
            }
        }
        return res >= n;
    }
};