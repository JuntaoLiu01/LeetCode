class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string res="";
        sort(A.begin(),A.end());
        do{
            string hour,minute;
            hour.push_back(char(A[0]+'0'));hour.push_back(char(A[1]+'0'));
            minute.push_back(char(A[2]+'0'));minute.push_back(char(A[3]+'0'));
            int h = stoi(hour),m = stoi(minute);
            res = (h <= 23 && m <= 59)?(hour+":"+minute):res;
        }
        while(next_permutation(A.begin(),A.end()));
        return res;
    }
};