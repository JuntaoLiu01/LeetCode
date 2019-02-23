class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n,0);
        vector<bool> visited(n,false);
        int index = 0;
        sort(deck.begin(),deck.end());
        res[index] = deck[0];visited[0] = true;
        for(int i = 1;i < n;i++){
            while(visited[index]) 
                index = (index+1) % n;
            index = (index+1) % n;
            while(visited[index])
                index = (index+1) % n;
            res[index] = deck[index];
            visited[index] = true;
        }
        return res;
    }
};