class Solution {
public:
    bool isValid(int x,int y){
        int t = sqrt(x+y);
        return t*t == x+y;
    }
    void dfs(vector<int> &A,vector<int> &tmp,vector<bool> &visited,int &res){
        if(tmp.size() == A.size()){
            res++;
            return;
        }
        for(int i = 0;i < A.size();i++){
            if(visited[i])
                continue;
            if(i > 0 && !visited[i-1] && A[i]==A[i-1])
                continue;
            if(!tmp.empty() && !isValid(tmp.back(),A[i]))
                continue;
            tmp.push_back(A[i]);
            visited[i] = true;
            dfs(A,tmp,visited,res);
            visited[i] = false;
            tmp.pop_back();
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        vector<bool> visited(n,false);
        vector<int> tmp;
        int res = 0;
        sort(A.begin(),A.end());
        dfs(A,tmp,visited,res);
        return res;
    }
};