#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int max = 0;
        while(left < right){
            int cur = min(height[left],height[right]) * (right-left);
            if(cur > max)
                max = cur;
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return max;    
    }
};