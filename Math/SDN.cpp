class Solution {
private:
    bool isDividing(int a){
        int c = a, b;
        while(c){
            b = c % 10;
            c = c / 10;
            if(!b)
                return false;
            if(a % b)
                return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left;i <= right;i++)
            if(isDividing(i))
                res.push_back(i);
        return res;
    }
};