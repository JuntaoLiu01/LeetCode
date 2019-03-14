class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1,pre = 0;
        for(int i = 1;i < chars.size();i++){
            if(chars[i]==chars[i-1])
                count++;
            else{
                if(count > 1){
                    string t = to_string(count);
                    chars.erase(chars.begin()+pre+1,chars.begin()+pre+count);
                    int k = pre+1;
                    for(int j = 0;j < t.size();j++,k++)
                        chars.insert(chars.begin()+k,t[j]);
                    i = pre + t.size()+1;
                    pre = i;
                }
                else
                    pre++;
                count = 1;
            }
        }
        if(count > 1){
            string t = to_string(count);
            chars.erase(chars.begin()+pre+1,chars.begin()+pre+count);
            int k = pre+1;
            for(int j = 0;j < t.size();j++,k++)
                chars.insert(chars.begin()+k,t[j]);
        }
        return chars.size();
    }
};