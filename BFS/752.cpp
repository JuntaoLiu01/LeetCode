class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(),deadends.end());
        string start = "0000";
        if(s.count(start))
            return -1;
        if(start == target)
            return 0;
        queue<string> q;
        unordered_set<string> visited;
        int res = 0;
        q.push(start);
        while(!q.empty()){
            res++;
            int n = q.size();
            for(int i = 0;i < n;i++){
                string t = q.front();
                q.pop();
                
                for(int j = 0;j < 4;j++){
                    for(int k=-1;k <= 1;k+=2){
                        string next = t;
                        next[j] = (next[j]-'0'+k+10)%10+'0';
                        if(next==target)
                            return res;
                        if(s.count(next) || visited.count(next))
                            continue;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};