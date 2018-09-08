#include <vector>

using namespace std;

class Solution {
private:
    void cs3(vector<vector<int> >& res,vector<int>& tmp,int level,int k,int n){
        if(n < 0)
            return;
        if(n == 0 && tmp.size() == k)
            res.push_back(tmp);
        for(int i = level; i <= 9; i++){
            tmp.push_back(i);
            cs3(res,tmp,i+1,k,n-i);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> tmp;
        cs3(res,tmp,1,k,n);
        return res;
           
    }
};