class Solution {
struct Point{
    int x;
    int y;
    Point(int _x,int _y):x(_x),y(_y){}
    friend bool operator < (const Point& p1,const Point& p2){
        if(p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y;
    }
    friend bool operator == (const Point& p1,const Point& p2){
        return p1.x==p2.x && p1.y==p2.y;
    }
    friend Point operator + (const Point& p1,const Point& p2){
        return Point(p1.x+p2.x,p1.y+p2.y);
    }
    friend Point operator - (const Point& p1,const Point& p2){
        return Point(p1.x-p2.x,p1.y-p2.y);
    }
    friend int cross(const Point& p1,const Point& p2){
        return p1.x*p2.y - p1.y*p2.x;
    }
    friend int dot(const Point& p1,const Point& p2){
        return p1.x*p2.x + p1.y*p2.y;
    }
};
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        set<Point> s;
        vector<Point> p;
        for(auto point:points){
            p.emplace_back(point[0],point[1]);
            s.insert(p.back());
        }
        int n = p.size();
        int res = -1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j)
                    continue;
                for(int k = 0;k < n;k++){
                    if(k==i || k==j)
                        continue;
                    if(dot(p[i] - p[j], p[k] - p[j]) != 0) 
                        continue;
                    Point p4 = p[k] + p[i] - p[j];
                    if(s.find(p4) != s.end()){
                        int area = abs(cross(p[i] - p[j], p[k] - p[j]));
                        res = res==-1?area:min(area,res);
                    }
                }
            }
        }
        return res==-1?0:res;
    }
};