class StreamChecker {
public:
    string q;
    unordered_map<int,unordered_set<string>> m;
    int maxl;
    StreamChecker(vector<string>& words) {
        maxl = 0;
        for(string w:words){
            maxl = max(int(w.length()),maxl);
            m[w.length()].insert(w);
        }
    }
    
    bool query(char letter) {
        q += string(1,letter);
        if(q.length() > maxl){
             q = q.substr(q.length()-maxl,maxl);
            for(auto p:m){
                if(p.second.count(q.substr(q.length()-p.first,p.first)))
                    return true;
            }
            return false;
        }
        for(auto p:m){
            if(q.length() >= p.first)
                if(p.second.count(q.substr(q.length()-p.first,p.first)))
                    return true;
        } 
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */