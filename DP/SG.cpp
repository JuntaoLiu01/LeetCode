class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int> > res(n,vector<int>(n,0));
        for(int i = 0;i < n;i++)
            res[i][i] = piles[i];
        for(int dis  = 1;dis < n;dis++){
            for(int i = 0;i < n-dis;i++)
                res[i][i+dis] = max(piles[i]-res[i+1][i+dis],piles[i+dis]-res[i][i+dis-1]);
        }
        return res[0][n-1]>0;
    }
};