class Solution {
public:
    map<char,int> m;
    bool compare(string& a,string& b){
        int la = a.size(),lb = b.size();
        int l = min(la,lb);
        for(int i = 0;i < l;i++){
            if(m[a[i]] < m[b[i]])
                return true;
            if(m[a[i]] > m[b[i]])
                return false;
        }
        if(la == l)
            return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0;i < order.size();i++)
            m[order[i]] = i;
        for(int i = 0;i < words.size()-1;i++){
            if(!compare(words[i],words[i+1]))
                return false;
        }
        return true;
    }
};