class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size(),i = 0;
        for(int a:pushed){
            s.push(a);
            while(!s.empty() && s.top()==popped[i]){
                s.pop();
                i++;
            }
        }
        return i==n;
    }
};