class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for(int i = 0;i < heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                int cur = s.top();
                s.pop();
                res = max(res,heights[cur]*(s.empty()?i:i-s.top()-1));
            } 
            s.push(i);
        }
        return res;
    }
};