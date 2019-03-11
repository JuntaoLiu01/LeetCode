class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int row = click[0],col = click[1];
        if(board[row][col]=='M')
            board[row][col] = 'X';
        else{
            int count = 0;
            for(int i = -1;i < 2;i++){
                for(int j = -1;j < 2;j++){
                    if(i==0 && j==0) continue;
                    int r = row+i,c = col+j;
                    if(r<0 || r>=m || c<0 || c>=n) continue;
                    if(board[r][c]=='M' || board[r][c]=='X')
                        count++;
                }
            }
            if(count>0)
                board[row][col] = char(count+'0');
            else{
                board[row][col] = 'B';
                for(int i = -1;i < 2;i++){
                    for(int j = -1;j < 2;j++){
                        if(i==0 && j==0) continue;
                        int r=row+i,c=col+j;
                        if(r<0 || r>=m || c<0 || c>=n)
                            continue;
                        if(board[r][c]=='E'){
                            vector<int> t{r,c};
                            updateBoard(board,t);
                        }
                            
                    }
                }
            }
        }
        return board;
    }
};