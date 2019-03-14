class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s;
        for(string str:banned)
            s.insert(str);
        int n = paragraph.size();
        string t;t.resize(n);
        transform(paragraph.begin(),paragraph.end(),t.begin(),::tolower);
        istringstream is(t);
        map<string,int> m;
        int  i = 0;
        while(i < n){
            if(!isalpha(t[i]))
                i++;
            else {
                int j = i;
                while(isalpha(t[j]))
                    j++;
                string str = t.substr(i,j-i);
                if(!s.count(str))
                    m[str]++;
                i = j;
            }
        }
        string res = "";
        int cnt = 0;
        for(auto p:m){
            if(p.second > cnt){
                res = p.first;
                cnt = p.second;
            }
        }
        return res;
    }
};