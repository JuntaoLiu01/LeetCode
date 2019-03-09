class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> res;
        int l=0,h=n;
        for(int i = 0;i < n;i++){
            if(S[i] == 'I')
                res.push_back(l++);
            else
                res.push_back(h--);
        }
        res.push_back(l);
        return res;
    }
};