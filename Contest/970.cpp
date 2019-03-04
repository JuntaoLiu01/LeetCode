class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        vector<int> res;
        for(int a = 1;a < bound;a *= x){
            for(int b = 1;a+b <= bound; b *= y){
                s.insert(a+b); 
                if(y == 1)
                    break;
            }
            if(x == 1)
                break;
        }
                                           
        for(auto num:s)
            res.push_back(num);
        return res;
    }
};