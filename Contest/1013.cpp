class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> temp(60,0);
        for(int i = 0;i < time.size();i++)
            temp[time[i]%60]++;
        int res = 0;
        for(int i = 1;i < 30;i++)
            res += temp[i]*temp[60-i];
        if(temp[0])
            res += temp[0]*(temp[0]-1)/2;
        if(temp[30])
            res += temp[30]*(temp[30]-1)/2;
        return res;
    }
};