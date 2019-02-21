class Solution {

public:
    bool gcd(int a,int b){
        if(a < b){
            int t = b;
            b = a;
            a = t;
        }
        int r = a%b;
        while(r != 0){
            a = b;
            b = r;
            r = a%b;
        }
        return b == 1;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        for(int i = 0;i < deck.size();i++)
            m[deck[i]]++;
        int p = m[deck[0]];
        for(auto it=m.begin();it != m.end();it++)
            if(gcd(it->second,p))
                return false;
        if(p < 2)
            return false;
        return true;
    }
};