class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        size_t found = haystack.find(needle);
        if(found==string::npos)
            return -1;
        return found;  
    }
};