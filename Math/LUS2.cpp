#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end(),[](string& a,string& b){
            if(a.size()==b.size())
                return a>b;
            else
                return a.size()>b.size();
        });
        unordered_set<string> s;
        for(int i = 0;i < n;i++){
            if(i == n-1 || strs[i]!=strs[i+1]){
                bool found = true;
                for(auto str:s){
                    int j = 0;
                    for(auto ch:str){
                        if(ch==strs[i][j])
                            j++;
                        if(j == strs[i].size()){
                            found = false;
                            break;
                        }
                    }
                }
                if(found)
                    return strs[i].size();
            }
            s.insert(strs[i]);
        }
        return -1;

    }
};