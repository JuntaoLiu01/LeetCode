
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> um;
        int res = 0;
        for(auto ans:answers)
            um[ans]++;
        for(auto it:um){
            int t = (it.second)/(it.first+1);
            if(it.second%(it.first+1))
                t++;
            res += t * (it.first+1);
        } 
        return res;
    }
};