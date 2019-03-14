class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1=name.size(),n2 = typed.size();
        int i = 0,j = 0;
        char pre = name[0];
        while(i < n1 && j < n2){
            if(typed[j] == name[i]){
                pre = name[i];
                i++;
                j++;
            }
            else if(typed[j] == pre)
                j++;
            else
                return false;
        }
        return i==n1;
    }
};