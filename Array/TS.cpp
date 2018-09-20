#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        priority_queue<int> q;
        int cycle = n+1,res = 0;
        for(char ch:tasks)
            m[ch]++;
        for(auto it:m)
            q.push(it.second);
        while(!q.empty()){
            vector<int> tmp;
            int cnt = 0;
            for(int i = 0;i < cycle;i++){
                if(!q.empty()){
                    tmp.push_back(q.top());
                    q.pop();
                    cnt++;
                }
            }
            for(int d:tmp){
                if(--d>0)
                    q.push(d);
            }
            res += q.empty()?cnt:cycle;
        }
        return res;
    }
};