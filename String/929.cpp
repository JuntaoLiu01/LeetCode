class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string email:emails){
            bool plus = false;
            bool at = false;
            string e = "";
            for(char ch:email){
                if(ch=='.'){
                    if(!at)
                        continue;
                }
                if(ch=='@')
                    at = true;
                if(ch=='+'){
                    if(!at){
                        plus = true;
                        continue;
                    }
                }
                if(!at && plus)
                    continue;
                e += ch;
            }
            s.insert(e);
        }
        return s.size();
    }
};