#include <vector> 
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        for(int i = 0;i < timeSeries.size();i++){
            if(i > 0 && timeSeries[i-1] + duration > timeSeries[i])
                sum += timeSeries[i]-timeSeries[i-1];
            else
                sum += duration;
        }
        return sum;
    }
};