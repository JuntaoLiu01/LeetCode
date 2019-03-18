class Solution {
public:
    int scoreOfParentheses(string S) {
        return dfs(s,0,S.size()-1);
    }
    int dfs(string s,int l,int r){
        if(r-l==1)
            return 1;
        int count = 0;
        for(int i = l;i < r;i++){
            if(s[i]=='(')
                count++;
            if(s[i]==')')
                count--;
            if(count==0)
                return dfs(s,l,i) + dfs(s,i+1,r);
        }
        return 2*dfs(s,l+1,r-1);
    }
};