class Solution {
public:
    void reverse_string(string& str){
        int n = str.size();
        for(int i = 0;i < n/2;i++){
            char tmp = str[i];
            str[i] = str[n-1-i];
            str[n-1-i] = tmp;
        }
    }
    string bigIntAdd(string a,string b){
        reverse_string(a);reverse_string(b);
        string res;
        int l1=a.size(),l2=b.size();
        int n1=min(l1,l2),n2=max(l1,l2);
        int si=0,s=0;
        for(int i = 0;i < n1;i++){
            int a1=a[i]-'0',a2=b[i]-'0';
            if(a1+a2+si < 10){
                s = a1+a2+si;
                si = 0;
            }
            else{
                s = a1+a2+si-10;
                si = 1;
            }
            res.push_back(char(s));
        }
        if(l1==n1){
            for(int i = n1;i < n2;i++){
                int a2 = b[i]-'0';
                if(a2 + si < 10){
                    s = a2+si;
                    si = 0;
                }
                else{
                    s = a2+si-10;
                    si = 1;
                }
                res.push_back(char(s));
            }
        }
        else{
            for(int i = n1;i < n2;i++){
                int a1=a[i]-'0';
                if(a1+si < 10){
                    s = a1+si;
                    si = 0;
                }
                else{
                    s = a1+si-10;
                    si = 1;
                }
                res.push_back(char(s));
            }
        }
        if(si==1)
            res.push_back(char(1));
        reverse_string(res);
        return res;
    }
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        string a ;
        for(int i = 0;i < n;i++)
            a.push_back(char(A[i]+'0'));
        string t = bigIntAdd(a,to_string(K));
        vector<int> res;
        for(int i = 0;i < t.size();i++)
            res.push_back(t[i]);
        return res;
    }
};