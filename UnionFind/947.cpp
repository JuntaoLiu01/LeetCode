class Solution {
public:
    vector<int> p;
    vector<int> s;
    void init(int n){
        for(int i = 0;i < n;i++){
            p.push_back(i);
            s.push_back(1);
        }
    }
    int find(int a){
        while(p[a] != a){
            p[a] = p[p[a]];
            a = p[a];
        }       
        return a;
    }
    void join(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb)
            return;
        if(s[pa] < s[pb]){
            p[pa] = pb;
            s[pb] += s[pa];
        }
        else{
            p[pb] = pa;
            s[pa] += s[pb];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int N = 10000;
        init(2*N);
        for(auto stone:stones)
            join(stone[0],stone[1]+N);
        unordered_set<int> us;
        for(auto stone:stones)
            us.insert(find(stone[0]));
        return stones.size()-us.size();
    }
};