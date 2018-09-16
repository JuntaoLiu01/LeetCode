#include <vector>
#include <math.h>

using namespace std;

class Solution {
private:
    double length(vector<int> A,vector<int> B){
        return sqrt(pow(float(A[0]-B[0]),2.0)+pow(float(A[1]-B[1]),2.0));
    }
    double area(double a,double b,double c){
        if( a+b<c || abs(a-b) > c)
            return 0;
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
public:
    double largestTriangleArea(vector<vector<int> >& points) {
        double res = 0;
        for(int i = 0;i < points.size()-2;i++)
            for(int j = i+1;j < points.size()-1;j++)
                for(int k = j+1;k < points.size();k++){
                    double a = length(points[i],points[j]);
                    double b = length(points[i],points[k]);
                    double c = length(points[j],points[k]);
                    double t = area(a,b,c);
                    res = max(res,t);
                }

        return res;
    }
};