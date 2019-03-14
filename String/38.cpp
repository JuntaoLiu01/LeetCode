class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while(--n){
            string t;
            for(int i = 0;i < res.size();i++){
                int count = 1;
                while(i+1 < res.size() && res[i]==res[i+1]){
                    i++;
                    count++;
                }
                t += to_string(count) + res[i];
            }
            res = t;
        }
        return res;
    }
};