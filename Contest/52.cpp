class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n,-1);
        DFS(0,pos,res);
        return res.size();
    }
    void DFS(int row,vector<int> &pos,vector<vector<string> > &res){
        int n = pos.size();
        if(row < n){
            for(int col = 0;col < n;col++){
                if(isValid(pos,row,col)){
                    pos[row]=col;
                    DFS(row+1,pos,res);
                    pos[row]=-1;
                }
            }
        }
        else{
            vector<string> tmp(n,string(n,'.'));
            for(int i = 0;i < n;i++)
                tmp[i][pos[i]] = 'Q';
            res.push_back(tmp);
        }
    }
    bool isValid(vector<int> pos,int row,int col){
        for(int i = 0;i < row;i++){
            if(col == pos[i] || abs(col-pos[i])==abs(row-i))
                return false;
        }
        return true;
    }
};