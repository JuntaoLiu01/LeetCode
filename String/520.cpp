class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n==1)
            return true;
        if(islower(word[0])){
            for(int i = 1;i < word.size();i++)
                if(isupper(word[i]))
                    return false;
        }else{
            bool upper = false,lower = false;
            for(int i = 1;i < word.size();i++){
                if(isupper(word[i])){
                    if(lower)
                        return false;
                    upper = true;
                }
                    
                else if(islower(word[i])){
                    if(upper)
                        return false;
                    lower = true;
                }
                    
            }
        }
        return true;
        
    }
};