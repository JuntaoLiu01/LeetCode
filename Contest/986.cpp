/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;
        int m = A.size();
        int n = B.size();
        if(m==0 || n==0)
            return res;
        int i = 0,j = 0;
        while(i < m && j < n){
            Interval a = A[i];
            Interval b = B[j];
            if(a.end < b.start)
                i++;
            else if(a.start > b.end)
                j++;
            else{
                res.push_back(Interval(max(a.start,b.start),min(a.end,b.end)));
                if(a.end <= b.end)
                    i++;
                else
                    j++;
            }
        }
        return res;
    }
};