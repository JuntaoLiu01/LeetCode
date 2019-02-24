class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(false);
        for(int i = 0;i < n;i++){
            if(visited[i])
                continue;
            visited[i] = true;
            map<int,int> m;
            int cur = i;
            while(true){
                int next = (cur + nums[cur] + n) % n;
                if(cur == next || nums[cur]*nums[next] < 0)
                    break;
                if(m.count(next))
                    return true;
                m[cur] = next;
                cur = next;
                visited[next] = true;
            }
        }
        return true;
    }
};