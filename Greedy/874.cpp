class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> s;
        for(auto o:obstacles)
            s.insert(to_string(o[0]) + "," + to_string(o[1]));
        int f = 0;
        int x = 0,y = 0;
        int xy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int res = 0;
        for(auto com:commands){
            if(com == -1)
                f = (f+1)%4;
            else if(com == -2)
                f = (f-1+4)%4;
            else if(com >= 1 && com <= 9){
                bool t = true;
                for(int i = 1;i <= com && t;i++){
                    if(s.find(to_string(x+xy[f][0])+","+to_string(y+xy[f][1])) != s.end())
                        t = false;
                    else{
                        x += xy[f][0];
                        y += xy[f][1];
                    }
                }
                res = max(res,x*x + y*y);
            }
        }
        return  res;
    }
};