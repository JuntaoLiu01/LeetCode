#include <vector>
#include <string>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string,string>> s;
        for(auto str:A){
            string t1,t2;
            for(int i = 0;i < str.size();i++){
                if(i%2) 
                    t1 += str[i];
                else
                    t2 += str[i];
            }
            sort(t1.begin(),t1.end());
            sort(t2.begin(),t2.end());
            s.insert(make_pair(t1,t2));
        }
        return s.size();      
    }
};